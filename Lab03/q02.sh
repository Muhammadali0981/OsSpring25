#!/bin/bash

# Read input sentence
read -p "Enter a sentence: " sentence

# Count vowels
count=$(echo "$sentence" | grep -o -i "[aeiou]" | wc -l)

# Print result
echo "Number of vowels: $count"
