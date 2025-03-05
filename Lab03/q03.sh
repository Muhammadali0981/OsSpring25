#!/bin/bash

# Check if filename is provided
if [ $# -ne 1 ]; then
    echo "Usage: $0 filename"
    exit 1
fi

filename=$1

# Check if the file exists
if [ -f "$filename" ]; then
    # Append date and time
    echo "Appended on: $(date)" >> "$filename"
    echo "Date and time appended to $filename."
else
    echo "File does not exist."
fi
