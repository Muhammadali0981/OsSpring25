#!/bin/bash

# Check if two arguments are provided
if [ $# -ne 2 ]; then
    echo "Usage: $0 num1 num2"
    exit 1
fi

# Multiply the numbers
result=$(( $1 * $2 ))

# Print the result
echo "Multiplication of $1 and $2 is: $result"
