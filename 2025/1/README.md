# Input Parser for Advent of Code 2025

This project contains a C program that parses input data from a file and stores it in a 2D array.

## File Description

- `parser.c` - C program that reads and parses the input file
- `input` - Input data file containing direction (L/R) and numeric values

## Input Format

Each line in the input file follows this format:
```
L4
R49
L25
```

Where:
- First character: `L` or `R` (direction)
- Remaining characters: A numeric value

## Parsing Logic

The program converts each line into a 2D array:
- **First index (column 0)**: Direction value
  - `L` → `0`
  - `R` → `1`
- **Second index (column 1)**: The numeric value

## Compilation and Execution

### Using GCC

To compile the program:
```bash
gcc -o parser parser.c
```

This will create an executable named `parser`.

### Running the Program

After compilation, run the program:
```bash
./parser
```

### One-Line Compile and Run

You can also compile and run in a single command:
```bash
gcc -o parser parser.c && ./parser
```

## Output

The program will:
1. Parse all rows from the `input` file
2. Display the total number of rows parsed
3. Show a sample of the first 10 rows
4. Display the last row for verification

Example output:
```
Successfully parsed 4570 rows

Sample of first 10 rows:
Row	Direction	Value
---	---------	-----
1	0 (=L)		4
2	1 (=R)		49
3	0 (=L)		25
...
```

## Requirements

- GCC compiler
- Input file named `input` in the same directory as the program

## Notes

- Maximum rows supported: 5000 (adjustable via `MAX_ROWS` in the code)
- The program uses a 2D integer array: `int data[MAX_ROWS][2]`
- The parsed data is stored in memory and can be used for further processing
