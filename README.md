File Operations Manager
A simple command-line program written in C that manages student records in a text file. The program allows you to write, read, append, and delete records with a user-friendly menu interface.
Features

Write Records (w) - Create a new file and add student records
Append Records (a) - Add new records to an existing file
Read Records (r) - Display all records in a formatted table
Delete Records (d) - Remove a specific record by student name
Exit (e) - Close the program

Data Structure---------------------
Each record contains the following information:
Name (string, max 50 characters)
Grade (string, max 10 characters)
Age (integer)
-----------------------------------
-----------------------------------
Compilation
bashgcc -o file_ops program.c
----------------------------------
Running the Program
bash./file_ops

The program will display an interactive menu. Enter the desired operation code and follow the prompts.

Data File: text.txt - Stores all student records in plain text format
Temporary File: temp.txt - Used internally during delete operations (automatically cleaned up)

