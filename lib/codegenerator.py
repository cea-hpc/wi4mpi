#!/usr/bin/env python3
"""
This module provides the abstract classe and methods for generating MPI translation code files.

"""

import os
from abc import abstractmethod, ABC
import re
from logging import getLogger
from logging.config import fileConfig
import jinja2
from textoperator import (
    clang_format,
    load_json_file,
    remove_file,
    write_file_append,
)

fileConfig(os.path.join(os.path.dirname(os.path.abspath(__file__)), "logging.conf"))
log = getLogger("code_logger")


class CodeGenerator(ABC):
    """
    Class for generating MPI translation code files.

    This class contains methods for generating MPI translation code files.

    Attributes:
        json_files (dict): json file path.
        jinja_files (dict): Template file path.
        data (dict): Load of json file.
        output_file (str): Output file path.
        dir_input (str): Input directory path.

    Methods:
        set_directories: Set input and output directories for code generation.
        __init__: Initialize the CodeGenerator object.

    """  # noqa: E501

    json_files = None
    data = None
    output_file = ""
    dir_input = ""
    static_sources_dir = ""
    dir_output = ""
    apply_jinja_dict = {
        "asm_dict": {},
        "app_dict": {},
        "run_dict": {},
        "dlsym_dict": {},
    }
    dico_jinja_env = dict()

    def set_directories(self, dir_input, dir_output):
        """
        Set input and output directories for header generation.

        Args:
            dir_input (str, optional): The input directory path. Defaults to "".
            dir_output (str, optional): The output directory path. Defaults to "".

        Returns:
            None
        """
        self.dir_input = dir_input
        self.dir_output = dir_output
        os.makedirs(self.dir_output, exist_ok=True)
        self.output_file = os.path.join(dir_output, self.output_file)
        self.json_files = {
            "functions_definitions": os.path.join(dir_input, "../common/jsons/functions.json"),
            "functions_mappers": os.path.join(dir_input, "jsons/mappers.json"),
            "types": os.path.join(dir_input, "../common/jsons/types.json"),
            "exceptions": os.path.join(dir_input, "../common/jsons/exceptions.json"),
        }
        self.data = {
            "functions": load_json_file(self.json_files["functions_definitions"]),
            "mappers": load_json_file(self.json_files["functions_mappers"]),
            "types": load_json_file(self.json_files["types"]),
            "exceptions": load_json_file(self.json_files["exceptions"]),
        }

    def typevar(self, var, typename):
        """
        Generate a type declaration string based on the variable name and type.

        Args:
            var (str): The variable name with potential array brackets.
            typename (str): The type name.

        Returns:
            str: The type declaration string.

        Example:
            >>> obj = YourClassName()
            >>> obj.typevar("arr[10]", "int")
            'int **********arr'
        """
        pattern = r"\[[0-9]*\]"
        sub = re.split(pattern, var)
        ret = typename + " " + "*" * len(sub[1:]) + sub[0]
        return ret

    def init_jinja(self):
        """
        Set the name of all jinja templates.
        Initialize all environment and store it in the dictionnary 'dico_jinja_env'.
        This dictionnary is a class attribute.
        """
        jinja_files = {
            "declarations": "template_declarations.jinja",
            "static": "template_static.jinja",
            "asm": "template_asm.jinja",
            "app": "template_A.jinja",
            "run": "template_R.jinja",
            "dlsym": "template_dlsym.jinja",
            "dlsym_interface": "template_dlsym_interface.jinja",
            "interface": "template_interface.jinja",
            "interface_entry": "template_interface_entry.jinja",
        }
        static_sources_dir = os.path.join(self.dir_input, "static_sources/")
        jinja_dir = os.path.join(self.dir_input, "templates/")
        for jinja_name in jinja_files.keys():
            jinja_env = jinja2.Environment(
                loader=jinja2.FileSystemLoader([jinja_dir, static_sources_dir]),
                trim_blocks=True,
            )
            jinja_env.filters["typevar"] = self.typevar
            self.dico_jinja_env[jinja_name] = jinja_env.get_template(jinja_files[jinja_name])

    def apply_jinja(self, jinja_name, param_dict):
        """
        generate the code correponding to the application of the dictionary
        on a jinja template
        """
        _msg = f"Run generate {jinja_name}"
        log.debug(_msg)
        jinja_template = self.dico_jinja_env[jinja_name]
        rendered_template = jinja_template.render(param_dict)
        return rendered_template + "\n"

    def generate(self):
        """
        Common code between classes CPreloadGenerator and CInterfaceGenerator
        """
        self.init_jinja()
        remove_file(self.output_file)
        content = ""
        content += self.apply_jinja("static", {})
        content += self.apply_jinja(
            "declarations",
            {
                "funcs": self.data["functions"],
                "mappers": self.data["mappers"],
            },
        )
        self.apply_jinja_dict["asm_dict"].update({
            "mappers": self.data["mappers"],
            "conf": self.data["exceptions"],
        })
        self.apply_jinja_dict["app_dict"].update({
            "mappers": self.data["mappers"],
            "conf": self.data["exceptions"],
        })
        self.apply_jinja_dict["run_dict"].update({
            "mappers": self.data["mappers"],
            "conf": self.data["exceptions"],
        })
        self.apply_jinja_dict["dlsym_dict"].update({
            "funcs": self.data["functions"],
            "types": self.data["types"],
        })
        for function in self.data["functions"]:
            self.apply_jinja_dict["asm_dict"]["func"] = function
            self.apply_jinja_dict["app_dict"]["func"] = function
            self.apply_jinja_dict["run_dict"]["func"] = function
            content += self.apply_jinja("asm", self.apply_jinja_dict["asm_dict"])
            content += self.apply_jinja("app", self.apply_jinja_dict["app_dict"])
            content += self.apply_jinja("run", self.apply_jinja_dict["run_dict"])
        content += self.apply_jinja("dlsym", self.apply_jinja_dict["dlsym_dict"])
        write_file_append(self.output_file, content)
        clang_format(self.output_file)

    @abstractmethod
    def __init__(self):
        """
        Initialization
        """
