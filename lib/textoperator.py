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
