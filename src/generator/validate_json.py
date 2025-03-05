#!/usr/bin/env python3
#
# Python command: validate_json
#    Apply a JSON schema to a JSON file to validate it.
#    Example:
#        ./validate_json.py --schema etc/code/common/jsons/schemas/schema_functions.json --file etc/code/common/jsons/functions.json 
#
import argparse
import json
from jsonschema import validate
from jsonschema.exceptions import ValidationError
import sys

def validate_json(schema_path, file_path):
    # Load schema
    try:
        with open(schema_path, 'r') as schema_file:
            schema = json.load(schema_file)
    except Exception as e:
        print(f"Error while loading the JSON schema : {e}")
        sys.exit(1)
        return

    # Load JSON file
    try:
        with open(file_path, 'r') as json_file:
            data = json.load(json_file)
    except Exception as e:
        print(f"Error while loading the JSON file : {e}")
        sys.exit(1)
        return

    # Validate JSON
    try:
        validate(instance=data, schema=schema)
        print(f"The JSON file '{file_path}' is compliant with the schema '{schema_path}'.")
    except ValidationError as e:
        print(f"Validation failed : {e.message}")
        sys.exit(1)
    except Exception as e:
        print(f"Unknown error : {e}")
        sys.exit(1)

if __name__ == "__main__":
    # Configure arguments
    parser = argparse.ArgumentParser(description="Validate a JSON file with a schema.")
    parser.add_argument("--schema", required=True, help="Path to schema.")
    parser.add_argument("--file", required=True, help="Path to JSON file.")

    # Parse arguments
    args = parser.parse_args()

    # Launch validation
    validate_json(args.schema, args.file)

