# Wi4MPI Python Code Standards

This document outlines the code style and linter configurations for the Python
code of the Wi4MPI project. We use `flake8`, `pylint`, and `black` to enforce our coding standards.

## flake8: Minimal PEP8 Linter

Exceptions:

- **E203 (Whitespace Before ':')**: Not strictly PEP8 in handling whitespace before colons.
  Defer to `black` for this rule.
- **W291 (Trailing Whitespace)**: Does not support trailing whitespaces in docstrings,
  necessary for generating headers and matching strings. Defer to `pylint` and `black`.

## pylint: PEP8 and Python Good Practices

Exeptions:

- **"line-too-long"**: Cannot ignore only docstrings, so defer to `flake8` for line lengths.

## black : PEP8 formatter and coding style

Configurations:
- **Preview = True**: Ensures proper indentation of docstrings, aligning with PEP8.

This setup balances strict PEP8 adherence with practicality in code generation for Wi4MPI.

## Using the Wrapper Script (python\_linter/linter.sh)

To lint your Python code using our prescribed rules, you can use the provided wrapper script `linter.sh`. Here's how to use it:

```bash
$ scripts/python_linter/linter.sh ./lib
```

### Script Helper

```
Usage: python_linter.sh [-h] <file_or_directory>

This script formats and lints Python code. It utilizes 'black' for formatting, 'flake8'
for style guide enforcement, and 'pylint' for code analysis. Provide a Python file or
a directory as an argument.

Options:
  -h    Display this help message and exit

Special rules:
  - Max line size:
    The max line size is 100, but for some reasons, one cannot always compact comments
    or docstrings to less than 100 chars. To add an exception to a comment or a docstring,
    add "# noqa: E501" as a flake8 directive.
    Note: pylint "too-long-line" is disabled because docstrings management is a mess
    (and flake8 is enough).
    Example:
        """
        My docstring has lines bigger than 100 chars
        """  # noqa: E501
```

This script simplifies the process of maintaining consistent code style and quality within your project directory.
