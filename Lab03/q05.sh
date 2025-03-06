
# Check if directory path is provided
if [ $# -ne 1 ]; then
    echo "Usage: $0 directory_path"
    exit 1
fi

source_dir=$1
backup_dir="backup_$(date +%Y%m%d_%H%M%S)"

# Check if the directory exists
if [ ! -d "$source_dir" ]; then
    echo "Directory does not exist."
    exit 1
fi

# Create backup directory
mkdir -p "$backup_dir"

# Copy files and directories
cp -r "$source_dir"/* "$backup_dir"

# Count files and directories
num_files=$(find "$backup_dir" -type f | wc -l)
num_dirs=$(find "$backup_dir" -type d | wc -l)

# Provide feedback
echo "Backup completed. Files backed up: $num_files, Directories backed up: $num_dirs"
echo "Backup stored in: $backup_dir"
