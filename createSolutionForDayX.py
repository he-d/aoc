import os
import sys
import shutil

def create_solution_for_day(day):
    day_str = f"{day:02d}"  # Format as two digits, e.g., 7 -> "07"

    # Create folders and files in cpp/
    cpp_dir = os.path.join("cpp", day_str)
    os.makedirs(cpp_dir, exist_ok=True)

    shutil.copy2("solution.cpp", os.path.join(cpp_dir, "solution.cpp"))

    with open(os.path.join(cpp_dir, "test.txt"), "w") as f:
        f.write("")

    with open(os.path.join(cpp_dir, "input.txt"), "w") as f:
        f.write("")

    with open(os.path.join(cpp_dir, "README.md"), "w") as f:
        f.write("# Day {} (C++)\n".format(day_str))

    # Create folders and files in python/
    python_dir = os.path.join("python", day_str)
    os.makedirs(python_dir, exist_ok=True)

    shutil.copy2("solution.py", os.path.join(python_dir, "solution.py"))

    with open(os.path.join(python_dir, "test.txt"), "w") as f:
        f.write("")

    with open(os.path.join(python_dir, "input.txt"), "w") as f:
        f.write("")

    with open(os.path.join(python_dir, "README.md"), "w") as f:
        f.write("# Day {} (Python)\n".format(day_str))

    print(f"Created solution structure for day {day_str} in both cpp/ and python/ directories using template files.")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python3 createSolutionForDayX.py <day>")
        sys.exit(1)

    try:
        day = int(sys.argv[1])
        create_solution_for_day(day)
    except ValueError:
        print("Error: Day must be a number.")
        sys.exit(1)
