# Advent of Code 2024 - C++ Solutions

This repository contains my solutions for [Advent of Code 2024](https://adventofcode.com/2024), implemented in C++. Each day features unique coding challenges that test algorithmic problem-solving and optimization skills. 

GitHub repository: [AdventOfCode24](https://github.com/SejDreng/AdventOfCode24)

---

## Overview

Advent of Code is an annual event where participants solve a new challenge daily from December 1st to 25th. Each challenge is divided into two parts, where solving the first part unlocks the second.

In this repository:
- Solutions for each challenge are organized by date (e.g., `December 1st`, `December 2nd`).
- Both parts of a challenge (`Part 1` and `Part 2`) are implemented as separate files.
- Input data for challenges is stored in `input.txt` files.

---

## File Structure

Here’s the structure of the repository:

AdventOfCode24/<br>
├── .vscode/                  # VSCode configuration files<br>
│   ├── c_cpp_properties.json<br>
│   ├── launch.json<br>
│   ├── settings.json<br>
│   └── tasks.json<br>
├── December 1st/             # Solutions for December 1st<br>
│   ├── Part1/
│   │   └── part1_1.cpp        # Solution for Part 1
│   ├── Part2/
│   │   └── part2_1.cpp        # Solution for Part 2
│   ├── main.cpp           
│   ├── input.txt          # Input data for the challenge
│   └── main.exe           # Compiled executable for Part 1 & Part 2
├── December 2nd/             # Solutions for December 2nd
│   ├── Part1/
│   │   └── part1_2.cpp        # Solution for Part 1
│   ├── Part2/
│   │   └── part2_2.cpp        # Solution for Part 2
│   ├── main.cpp          
│   ├── input.txt          # Input data for the challenge
│   └── main.exe           # Compiled executable for Part 1 & Part 2

How to Run
Clone the repository:

git clone https://github.com/SejDreng/AdventOfCode24.git
cd AdventOfCode24
Navigate to the specific challenge directory (e.g., December 1st).

Compile the solution:
g++ -o main main.cpp

Run the compiled executable:
./main

Ensure the input.txt file is present in the same directory for the program to process the puzzle input.
