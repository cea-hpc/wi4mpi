import json
import os
import pytest
from textoperator import load_json_file

# Define the path to the validation script and test files
DATA_DIR    = os.path.join(os.path.dirname(__file__), "data/textoperator")

# Test case 1: Test the function with a valid file without filtering (no mpi_norm)
def test_load_json_file_no_filter():
    data = [
      {
        "args": [
          {
            "var": "level",
            "arg_dep": "",
            "In": 0,
            "name": "int_mapper",
            "Out": 0
          },
          {
            "variadic": "True"
          }
        ],
        "name": "MPI_Pcontrol",
        "ret": {
          "var": "ret",
          "arg_dep": "",
          "In": 0,
          "name": "error_converter",
          "Out": 1
        },
        "MPImin": 1.1,
        "MPImax": 4.0
      }
    ]

    result = load_json_file(
        os.path.join(DATA_DIR, "functions.json"),
        mpi_norm=None,
        schema_path=os.path.join(DATA_DIR, "schema_functions.json"),
    )

    assert result == data  # The result should be equal to `data` since there is no filtering

# Test case 2: Test with a valid file and filtering by mpi_norm
def test_load_json_file_with_filter():
    data = [
      {
        "args": [
          {
            "var": "file",
            "arg_dep": "",
            "Out": 0,
            "name": "fint_converter",
            "In": 1
          }
        ],
        "name": "MPI_File_f2c",
        "ret": {
          "var": "ret",
          "arg_dep": "",
          "Out": 1,
          "name": "file_converter",
          "In": 0
        },
        "MPImin": 2.0,
        "MPImax": 3.1
      }
    ]
    result = load_json_file(
        os.path.join(DATA_DIR, "functions_filter.json"),
        mpi_norm=2.0,
        schema_path=os.path.join(DATA_DIR, "schema_functions.json"),
    )

    # Filtering based on `mpi_norm`, so the result should include only the blocks where "MPImin" <= 2.0 <= "MPImax"
    assert result == data

# Test case 3: Test with a file where no block is compatible with mpi_norm
def test_load_json_file_no_compatible_blocks():
    with pytest.raises(ValueError, match="No blocks found compatible with mpi_norm=100.0"):
        load_json_file(
            os.path.join(DATA_DIR, "functions_filter.json"),
            mpi_norm=100.0,
            schema_path=os.path.join(DATA_DIR, "schema_functions.json"),
        )

# Test case 4: Test with a missing file (FileNotFoundError)
def test_load_json_file_file_not_found():
    with pytest.raises(FileNotFoundError):
        load_json_file("fake_path.json", mpi_norm=None, schema_path=None)

# Test case 5: Test with a file containing invalid JSON data (JSONDecodeError)
def test_load_json_file_invalid_json():
    with pytest.raises(json.JSONDecodeError):
        load_json_file(
            os.path.join(DATA_DIR, "invalid.json"),
            mpi_norm=None,
            schema_path=None,
        )

