import subprocess
import os
import pytest

# Define the path to the validation script and test files
SCRIPT_PATH = os.path.abspath("validate_json.py")
DATA_DIR    = os.path.join(os.path.dirname(__file__), "data/validate_json")

# Utility function to run the script with arguments
def run_command(schema, file):
    result = subprocess.run(
        ["python", SCRIPT_PATH, f"--schema={schema}", f"--file={file}"],
        capture_output=True,
        text=True,
    )
    return result

# Tests
def test_valid_json():
    schema = os.path.join(DATA_DIR, "valid_schema.json")
    file = os.path.join(DATA_DIR, "valid_file.json")
    result = run_command(schema, file)
    assert result.returncode == 0
    assert "is compliant with the schema" in result.stdout

def test_invalid_json():
    schema = os.path.join(DATA_DIR, "valid_schema.json")
    file = os.path.join(DATA_DIR, "invalid_file.json")
    result = run_command(schema, file)
    assert result.returncode != 0
    assert "Validation failed" in result.stdout

def test_invalid_schema():
    schema = os.path.join(DATA_DIR, "invalid_schema.json")
    file = os.path.join(DATA_DIR, "valid_file.json")
    result = run_command(schema, file)
    assert result.returncode != 0
    assert "Failed validating 'anyOf' in metaschema" in result.stdout

def test_missing_file():
    schema = os.path.join(DATA_DIR, "valid_schema.json")
    file = os.path.join(DATA_DIR, "missing_file.json")  # Nonexistent file
    result = run_command(schema, file)
    assert result.returncode != 0
    assert "Error while loading the JSON file" in result.stdout

