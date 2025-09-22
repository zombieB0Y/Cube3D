import subprocess
import sys
import os

# Default directory to check
CHECK_DIR = sys.argv[1] if len(sys.argv) > 1 else '.'

# File extensions to check
EXTENSIONS = ['.c', '.h']

def find_files(directory):
    files = []
    for root, _, filenames in os.walk(directory):
        for filename in filenames:
            if any(filename.endswith(ext) for ext in EXTENSIONS):
                files.append(os.path.join(root, filename))
    return files

def run_norminette(files):
    for file in files:
        print(f'Checking: {file}')
        result = subprocess.run(['norminette', file], capture_output=True, text=True)
        print(result.stdout)
        if result.stderr:
            print(result.stderr)

if __name__ == '__main__':
    files = find_files(CHECK_DIR)
    if not files:
        print('No .c or .h files found.')
        sys.exit(1)
    run_norminette(files)
