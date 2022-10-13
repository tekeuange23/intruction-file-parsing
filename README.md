# Intruction File Parsing

Precondition: there is a file with the following contents:

A data stream (numbers, series of numbers and ( optional) strings of letters), 
markers (chosen by you) and 
commands, 
each of which is surrounded by separators. 
Choose separators for the steps and other separators to 
other separators to separate the numbers in a series,

## Assigment
Develop a program that does the following:

1. The user can enter a file name.

2. The program reads the corresponding file.

3. The read file is processed step by step as follows:
    1. The file is processed sequentially (data flow).
    2. If unmarked data are present between two separators, they are temporarily stored in a buffer, 
       they are stored temporarily in a buffer. 3.
    3. (optional) If between two separators, 
     there are data with markers (their choice, before or after the data), 
     the data is stored in correspondence with the marker.
    4. (optional) If there is only one marker character between two separators, 
     the data are read from the buffer based on the associated marker character.
    5. If a command appears between two separators, the command is applied to the buffer (1-operand command).
    6. If a command containing data (any order) appears between two separators, the command containing the data is applied to the buffer (2-operand command).

4. The following commands must be possible:
    1. Buffer output
    (optional) Output Content Marker characters
    2. number: Increment/Decrement
    3. Number: Addition/Subtraction
    4. Number series: Addition/Subtraction
    5. Series of numbers: Sum of all numbers
    6. Number series : sorting of the series by ascending/decreasing order 
    7. ( optional ) Character strings : sorting of letters by ascending/decreasing order

5.  During processing, each step must be initiated by the user, 
    by means of keyboard input or keystroke. 

    It should be possible to proceed as follows:

    1. Execution of the next step
    2. Repeating the current step
    3. Return to the beginning of the file
    4. (bonus) Return variable number of steps

## Solution
```bash
$ gcc util.c parsing.c main.c -o exec ./exec
```
```bash
$ ./exec
```