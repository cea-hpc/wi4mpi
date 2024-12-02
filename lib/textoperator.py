#!/usr/bin/env python3
"""
This module provides functions for manipulating text by deleting, inserting lines, and removing fun
ction prototypes.

Functions:
- delete_lines(lines_to_delete, text): Delete specified lines from the given text.
- delete_line_from_pattern(pattern, text): Delete lines containing the specified pattern from the g
iven text.
- insert_lines(lines_to_insert, line_number, text): Inserts the specified lines at the given positi
on in the text.
- function_to_delete(text, pattern): Removes function prototypes containing the specified function
name from the given text.
- list_pattern_replacement(pattern, replacement, text, shift=False): Replace patterns with correspo
nding replacements in a given text.
- bloc_pattern_replacement(pattern_block, replacement_block, text): Replace a block pattern with a
replacement block in the given text.
- replace_bloc_from_conf_file(pattern_path, replace_path, text): Replace a block from the text base
d on configurations from files.
- replacement_from_conf_file(path_file, text, shift=False, replacement_file=None): Replace patterns
based on configurations from a file.
- write_conf_file(pattern, replacement, path_file): Write pattern-replacement configurations to a f
ile.
- delete_bloc_from_conf_file(path_file, text): Delete a block from the text based on configurations
from a file.
- clang_format: Format code.
- write_file_append: Add lines at the end of the input file.

Examples:
    original_text = "Line 1\nLine 2\nLine 3\nLine 4\n"
    delete_lines([2, "Line 4"], original_text)
    # Returns: 'Line 1\nLine 3\n'

    original_text = "Line 1\nLine with pattern ABC\nLine 3\n"
    delete_line_from_pattern("ABC", original_text)
    # Returns: 'Line 1\nLine 3\n'

    original_text = "Line 1\nLine 2\nLine 3\nLine 4\n"
    insert_lines(["New Line 1", "New Line 2"], 2, original_text)
    # Returns: 'Line 1\nNew Line 1\nNew Line 2\nLine 2\nLine 3\nLine 4\n'

    original_text = "void function1();\nint main();\nvoid function2();\n"
    function_to_delete(original_text, "function1")
    # Returns: 'int main();\nvoid function2();\n'
"""
import os
import re
import json
from subprocess import call


def delete_lines(lines_to_delete, text):
    """
    Delete specified lines from the given text.

    Parameters:
    - lines_to_delete (int, str, list): Line numbers (int), line content (str), or a list
      of line numbers or contents to be deleted from the text.
    - text (str): The input text from which lines are to be deleted.

    Returns:
    str: The modified text after deleting the specified lines.

    Example:
    >>> original_text = "Line 1\nLine 2\nLine 3\nLine 4\n"
    >>> delete_lines([2, "Line 4"], original_text)
    'Line 1\nLine 3\n'
    """
    lines = text.split("\n")
    if isinstance(lines_to_delete, (int, str)):
        lines_to_delete = [lines_to_delete]
    if isinstance(lines_to_delete[0], int):
        for line_number_to_delete in sorted(lines_to_delete, reverse=True):
            if 1 <= line_number_to_delete <= len(lines):
                del lines[line_number_to_delete - 1]
    elif isinstance(lines_to_delete[0], str):
        for line in lines_to_delete:
            try:
                del lines[lines.index(line)]
            except ValueError:
                continue
    return "\n".join(lines)


def delete_line_from_pattern(pattern, text):
    """
    Delete lines containing the specified pattern from the given text.

    Parameters:
    - pattern (str): The pattern to match for deleting lines.
    - text (str): The input text from which lines are to be deleted.

    Returns:
    str: The modified text after deleting lines containing the specified pattern.

    Example:
    >>> original_text = "Line 1\nLine with pattern ABC\nLine 3\n"
    >>> delete_line_from_pattern("ABC", original_text)
    'Line 1\nLine 3\n'
    """
    lines = text.split("\n")
    if isinstance(pattern, str):
        lines_to_delete = []
        for line in lines:
            if pattern in line:
                lines_to_delete.append(line)
        if lines_to_delete:
            text = delete_lines(lines_to_delete, text)
    return text


def insert_lines(lines_to_insert, line_number, text):
    """
    Inserts the specified lines at the given position in the text.

    Args:
        text (str): The original text.
        lines_to_insert (list): List of lines to insert.
        line_number (int): The line number where to insert the new lines.

    Returns:
        str: The modified text with the new lines inserted.
    """
    lines = text.split("\n")
    if 1 <= line_number <= len(lines):
        lines[line_number - 1 : line_number - 1] = lines_to_insert
    return "\n".join(lines)


def function_to_delete(text, pattern):
    """
    Removes function prototypes containing the specified function name from the given text.

    Args:
        text (str): The original text.
        pattern (str): The name of the function whose prototypes are to be removed.

    Returns:
        str: The modified text with function prototypes removed.
    """
    lines = text.split("\n")

    new_lines = []
    function_started = False
    function_ended = False

    for line in lines:
        if pattern in line and "(" in line:
            function_started = True
            function_ended = False
        if function_started and line.strip() == ";":
            function_started = False
            function_ended = True
        if function_started:
            if ";" in line:
                function_ended = True
        if not function_started and not function_ended:
            new_lines.append(line)
        if function_ended:
            function_started = False
            function_ended = False

    return "\n".join(new_lines)


def list_pattern_replacement(pattern, replacement, text, shift=False):
    """
    Replace patterns with corresponding replacements in a given text.

    Args:
        pattern (list): List of patterns to search for in the text.
        replacement (list): List of replacement strings corresponding to the patterns.
        text (str): The text in which to perform the replacements.
        shift (bool, optional): Indicates whether line shift should be returned. Defaults to False.

    Returns:
        str or tuple: The text with replacements applied, or a tuple with the modified text and the
        line shift if shift=True.
    """
    line_shift = 0  # Initialize line shift
    for _pattern, _replacement in zip(pattern, replacement):
        # Calculate line shift for each replacement
        line_shift += len(_replacement.split("\n")) - len(_pattern.split("\n"))
        # Perform replacement in the text
        text = re.sub(_pattern, _replacement, text, flags=re.MULTILINE)

    # Return modified text with or without line shift
    if shift:
        return text, line_shift  # Return text and line shift
    return text  # Return only the modified text


def bloc_pattern_replacement(pattern_block, replacement_block, text):
    """
    Replace a block pattern with a replacement block in the given text.

    Args:
        pattern_block (str): The block pattern to search for in the text.
        replacement_block (str): The replacement block.
        text (str): The text in which to perform the replacement.

    Returns:
        str: The modified text after replacing the block pattern with the replacement block.
    """
    text = re.sub(re.escape(pattern_block), replacement_block, text, flags=re.DOTALL)
    return text


def replacement_from_conf_file(path_file, text, shift=False, replacement_file=None):
    """
    Replace patterns based on configurations from a file.

    Args:
        path_file (str): The path to the configuration file containing patterns and replacements.
        text (str): The text in which to perform the replacements.
        shift (bool, optional): Indicates whether line shift should be returned. Defaults to False.
        replacement_file (str, optional): Path to a separate file containing the replacement. Defau
        lts to None.

    Returns:
        str or tuple: The modified text with replacements applied, or a tuple with the modified tex
        t and the
        line shift if shift=True.
    """
    line_shift = 0  # Initialize line shift
    if replacement_file:
        with open(path_file, "r", encoding="utf-8") as file_descriptor:
            _pattern = file_descriptor.read()
        with open(replacement_file, "r", encoding="utf-8") as file_descriptor:
            _replacement = file_descriptor.read()
        line_shift += len(_replacement) - len(_pattern)
        text = re.sub(re.escape(_pattern), _replacement, text, flags=re.DOTALL)
    else:
        with open(path_file, "r", encoding="utf-8") as file_descriptor:
            for line in file_descriptor.readlines():
                _pattern = line.split("@")[0]  # pattern and replacement are separated by "@"
                _replacement = line.split("@")[1][:-1]  # Do not take the last new line char
                line_shift += len(_replacement.split("\n")) - len(_pattern.split("\n"))
                text = re.sub(rf"{_pattern}", rf"{_replacement}", text, flags=re.MULTILINE)
    if shift:
        return text, line_shift  # Return text and line shift
    return text  # Return only the modified text


def write_conf_file(pattern, replacement, path_file):
    """
    Write pattern-replacement configurations to a file.

    Args:
        pattern (list): List of patterns to write to the file.
        replacement (list): List of corresponding replacements.
        path_file (str): The path to the file to write the configurations.
    """
    with open(path_file, "w", encoding="utf-8") as file_descriptor:
        for _pattern, _replacement in zip(pattern, replacement):
            file_descriptor.write(rf"{_pattern}" + "@" + rf"{_replacement}" + "\n")


def delete_bloc_from_conf_file(path_file, text):
    """
    Delete a block from the text based on configurations from a file.

    Args:
        path_file (str): The path to the configuration file containing the block to delete.
        text (str): The text from which to delete the block.

    Returns:
        str: The modified text after deleting the block.
    """
    with open(path_file, "r", encoding="utf-8") as file_descriptor:
        text = re.sub(re.escape(file_descriptor.read()), """""", text, flags=re.DOTALL)
    return text


def replace_bloc_from_conf_file(pattern_path, replace_path, text):
    """
    Replace a block from the text based on configurations from files.

    Args:
        pattern_path (str): The path to the configuration file containing the pattern.
        replace_path (str): The path to the configuration file containing the replacement.
        text (str): The text from which to replace the block.

    Returns:
        str: The modified text.
    """
    with open(pattern_path, "r", encoding="utf-8") as pattern_file:
        with open(replace_path, "r", encoding="utf-8") as replace_file:
            text = re.sub(
                re.escape(pattern_file.read()),
                replace_file.read(),
                text,
                flags=re.DOTALL,
            )
    return text



def load_json_file(file_path, mpi_norm=None):
    """
    Load a JSON file from the specified path and optionally filter
    blocks based on MPI version constraints (`MPImin`, `MPImax`).

    Args:
        file_path (str): The path to the JSON file.
        mpi_norm (float, optional): The MPI version to filter by.
                                  If None, all data is returned.

    Returns:
        list or dict: The JSON data loaded from the file, filtered
                      by MPI_norm if specified.

    Raises:
        FileNotFoundError: If the specified file is not found.
        JSONDecodeError: If an error occurs during JSON decoding.
        ValueError: If mpi_norm is specified but not compatible with any block.
    """
    # Load full file
    with open(file_path, "r", encoding="utf-8") as file_descriptor:
        data = json.load(file_descriptor)

    # If no filtering is required, return the full data
    if mpi_norm is None:
        return data

    # Check if data is an array
    if isinstance(data, list):
        filtered_data = [
            block for block in data
            if _is_block_valid_for_mpi(block, mpi_norm)
        ]
        if not filtered_data:
            raise ValueError(f"No blocks found compatible with mpi_norm={mpi_norm}")
        return filtered_data
    # Handle single JSON objects
    elif isinstance(data, dict):
        if _is_block_valid_for_mpi(data, mpi_norm):
            return data
        else:
            raise ValueError(f"No blocks found compatible with mpi_norm={mpi_norm}")

    # Unsupported JSON structure
    raise ValueError("Unsupported JSON structure for filtering")


def _is_block_valid_for_MPI(block, mpi_norm):
    """Helper function to check if a block is valid for the given MPI version."""
    mpi_min = block.get("MPImin")
    mpi_max = block.get("MPImax")

    # Check constraints
    if mpi_min is not None and mpi_norm < mpi_min:
        return False
    if mpi_max is not None and mpi_norm > mpi_max:
        return False

    return True


def clang_format(file_to_format):
    """
    Format code with LLVM style.

    Args:
        file_to_format (str): Path of the file to format.

    Returns:
        None
    """
    call(["clang-format", "-style=LLVM", "-i", file_to_format])


def write_file_append(file_to_edit, content):
    """
    Write lines at the end of the file.

    Args:
        file_to_edit (str): Path of the file to edit.
        content (str): Strings to append to the file.

    Returns:
        None
    """
    with open(file_to_edit, "a", encoding="utf-8") as file_descriptor:
        file_descriptor.write(content)


def remove_file(file_path):
    """
    Remove file if it exists.

    Args:
        file_path (str): Path of the file to remove

    Returns:
        None
    """
    if os.path.exists(file_path):
        os.remove(file_path)
