#!/bin/sh

# Determine the directory where the script is located
SCRIPT_DIR="$(dirname "$(realpath "$0")")"

# Configuration file paths
PYPROJECT_TOML="${SCRIPT_DIR}/pyproject.toml"
FLAKE8_CONF="${SCRIPT_DIR}/flake8.conf"

# Display help message
show_help() {
    cat << EOF
Usage: python_linter.sh [-h] <file_or_directory>

This script formats and lints Python code.
It uses 'black' for formatting, 'flake8' for style guide enforcement, and 'pylint' for code analysis.
Provide a Python file or a directory as an argument.

Options:
  -h    Display this help message and exit

Special rules:
  - Max line size:
    The max line size is 100, but for some reasons, one cannot always compact comments or docstrings to less than 100 chars.
    To add a exception to a comment or a dosctring, add "# noqa: E501" as flake8 directive.
    Note: pylint "too-long-line" is disabled because dosctrings management is a mess (and flake8 is enough).
    Example:
        """
        My docstring has lines bigger than 100 chars
        """  # noqa: E501
EOF
}

# Check for the presence of black, flake8, and pylint
command -v black >/dev/null 2>&1 || { echo >&2 "Error: black is not installed. Aborting."; exit 1; }
command -v flake8 >/dev/null 2>&1 || { echo >&2 "Error: flake8 is not installed. Aborting."; exit 1; }
command -v pylint >/dev/null 2>&1 || { echo >&2 "Error: pylint is not installed. Aborting."; exit 1; }

# Parse command-line options
while getopts "h" opt; do
    case $opt in
        h)
            show_help
            exit 0
            ;;
        \?)
            echo "Invalid option: -$OPTARG" >&2
            exit 1
            ;;
    esac
done

# Shift off the options and optional --
shift $((OPTIND-1))

# Check if an argument is provided
if [ $# -eq 0 ]; then
    echo "Error: No file or directory provided."
    show_help
    exit 1
fi

# Assign <file_or_directory> arg to TARGET
TARGET=$1

# Check if the provided target exists
if [ ! -e "$TARGET" ]; then
    echo "Error: The specified file or directory does not exist."
    exit 1
fi

# Add TARGET dir to PYTHONPATH
# Required for some PEP8 specifications like F401
if [ -d "$TARGET" ]; then
    export PYTHONPATH=$TARGET:$PYTHONPATH
elif [ -f "$TARGET" ]; then
    export PYTHONPATH=$(dirname $TARGET):$PYTHONPATH
fi

# Initialize return code variables
black_rc=0
flake8_rc=0
pylint_rc=0

# Run flake8
echo "== Running flake8 ..."
flake8 --config "$FLAKE8_CONF" "$TARGET" || flake8_rc=$?

# Run pylint
echo "== Running pylint ..."
pylint --rcfile="$PYPROJECT_TOML" "$TARGET" || pylint_rc=$?

# Run black
echo "== Running black ..."
black --config "$PYPROJECT_TOML" --check "$TARGET" || black_rc=$?

# Check return codes and display messages
if [ $flake8_rc -ne 0 ]; then
    echo "##############################################################"
    echo "Flake8 found style issues. Please fix them before committing."
fi

if [ $pylint_rc -ne 0 ]; then
    echo "############################################################"
    echo "Pylint found code issues. Please fix them before committing."
fi

if [ $black_rc -ne 0 ]; then
    echo "#################################################################"
    echo "Black found formatting issues. Please fix them before committing."
    echo "Run the following command to apply black formatting:"
    echo "    black --config $PYPROJECT_TOML $TARGET"
fi

# Check if any command failed
if [ $flake8_rc -ne 0 ] || [ $pylint_rc -ne 0 ] || [ $black_rc -ne 0 ]; then
    exit 1
else
    echo "All checks passed successfully."
fi

