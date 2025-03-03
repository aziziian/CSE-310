# CSE-310 Solo Project: Ian Azizi

# Project 1: Hash Table Encoder

## Description
This program implements a basic hash table to store and process strings. It takes input from a text file and inserts each word into the appropriate slot based on a hash function. The program then prints the contents of the hash table and relevant statistics.

## Compilation Instructions
To compile the program, run:

    make

To remove the compiled binary, use:

    make clean

## Running the Program
To execute the encoder with a given input file, use:

    ./encoder < common500.txt

⚠️ Be sure to include `<` before the filename, or the program will not read the input correctly.

If you encounter a "Permission Denied" error when running the program, fix it by running:

    chmod 777 encoder

## Expected Output
The program will print the words being inserted along with their respective hash slots. It will also output summary statistics such as slot lengths and standard deviation.
