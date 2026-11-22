# Arbitrary Precision Calculator (APC) in C

## Overview

The Arbitrary Precision Calculator (APC) is a C programming project that performs arithmetic operations on large integer numbers.

It uses a **Doubly Linked List (DLL)** to store and process individual digits of the input numbers. This approach allows arithmetic operations to be implemented digit by digit instead of relying on built-in integer data types.

The project supports four basic arithmetic operations: addition, subtraction, multiplication, and division.


## Features

- Addition of large integer numbers
- Subtraction of large integer numbers
- Multiplication of large integer numbers
- Division of large integer numbers
- Doubly Linked List-based number representation
- Command-line argument handling for operands and operators


## Technologies and Concepts Used

- C Programming
- Data Structures and Algorithms (DSA)
- Doubly Linked Lists
- Pointers
- Dynamic Memory Allocation
- Command-Line Arguments
- Arithmetic Operations


## Project Structure

| File | Description |
|---|---|
| `main.c` | Main function and command-line argument handling |
| `apc.h` | Structure definitions and function declarations |
| `addition.c` | Addition operation |
| `subtraction.c` | Subtraction operation |
| `multiplication.c` | Multiplication operation |
| `division.c` | Division operation |
| `insert_at_first.c` | Inserts a node at the beginning of the list |
| `insert_at_last.c` | Inserts a node at the end of the list |
| `print_list.c` | Displays the result stored in the linked list |


## Compilation

Compile all C source files using GCC:

```bash
gcc *.c -o apc
```

## Execution

Run the program using the following format:

```bash
./apc operand1 operator operand2
```

### Examples

```bash
./apc 123 + 456
./apc 1000 - 250
./apc 123 '*' 45
./apc 1000 / 25
```


## Concepts Practiced

- Doubly Linked List implementation
- Dynamic memory allocation and pointer manipulation
- Digit-by-digit arithmetic operations
- Carry and borrow handling
- Command-line argument processing
- Modular programming in C

## Author

**Sidharth Vinod**

B.Tech – Electronics and Communication Engineering

## Learning Journey

Developed as part of my C Programming and Data Structures learning journey.


