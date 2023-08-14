import os

SRC_DIR = "src"
HEADER_DIR = "header"
OUT_DIR = "out"

# Create the output directory if it doesn't exist
os.makedirs(OUT_DIR, exist_ok=True)

# Compile and link
cpp_files = [
    "carvoyage.cpp",
    "customer.cpp",
    "menu.cpp",
    "log.cpp",
    "car_manage.cpp"
]
cpp_files_with_paths = [os.path.join(SRC_DIR, file) for file in cpp_files]
header_flags = "-I " + HEADER_DIR
compile_command = f"g++ -o {os.path.join(OUT_DIR, 'my_program')} {' '.join(cpp_files_with_paths)} {header_flags}"
os.system(compile_command)

# Run the program
run_command = os.path.join(OUT_DIR, "my_program")
os.system(run_command)

print("Compilation and execution completed.")

