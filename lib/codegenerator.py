#!/usr/bin/env python3
"""
This module provides the abstract classe and methods for generating MPI translation code files.

"""

import os
from abc import abstractmethod, ABC
import re
import jinja2
from logging import getLogger
from logging.config import fileConfig
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

    json_files = {}
    jinja_files = {}
    data = {}
    output_file = ""
    dir_input = ""
    jinja_dir = ""
    static_sources_dir = ""
    dir_output = ""

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

#    @abstractmethod
#    def _generate_static_side(self):
#        """
#        Abstract method, must be implemented by a subclass.
#        Generate the static side of the output file using Jinja templates.
#        """
#
#    @abstractmethod
#    def _generate_declarations_side(self):
#        """
#        Abstract method, must be implemented by a subclass.
#        Generate the declarations side of the output file using Jinja templates.
#        """
#
#    @abstractmethod
#    def _generate_function(self, function, template_file):
#        """
#        Abstract method, must be implemented by a subclass.
#        Generate the function using Jinja templates.
#        """
#
#    @abstractmethod
#    def _generate_dlsym_side(self):
#        """
#        Abstract method, must be implemented by a subclass.
#        Generate the dlsym side of the output file using Jinja templates.
#        """
#
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

    def apply_jinja(self, jinja_name, param_dict):
        """
        generate the code correponding to the application of the dictionnary
        on a jinja template
        """
        _msg = f"Run generate {jinja_name}"
        log.debug(_msg)
        jinja_env = jinja2.Environment(
            loader=jinja2.FileSystemLoader([self.jinja_dir, self.static_sources_dir]),
            trim_blocks=True,
        )
        jinja_env.filters["typevar"] = self.typevar
        jinja_template = jinja_env.get_template(self.jinja_files[jinja_name])
        rendered_template = jinja_template.render(param_dict)
        return rendered_template + "\n"

    @abstractmethod
    def generate(self):
        """
        Abstract method, must be implemented by a subclass.
        Generate output_file.
        """

    @abstractmethod
    def __init__(self):
        """
        Initialization
        """
