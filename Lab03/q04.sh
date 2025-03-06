
# Check if argument is provided
if [ $# -ne 1 ]; then
    echo "Usage: $0 file_or_directory"
    exit 1
fi

item=$1

# Check file/directory status
if [ -f "$item" ]; then
    echo "$item is a file."
    ls -l "$item"
elif [ -d "$item" ]; then
    echo "$item is a directory."
    ls -ld "$item"
else
    echo "$item does not exist."
fi
