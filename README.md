*This project has been created as part of the 42 curriculum by mbardeau.*
# GET-NEXT-LINE  (GNL) - 42 Project

## Table of Contents

1. [Description](#description)
	- [Algorithm Explanation](#algorithm-explanation)
		- [ft_read_and_stash](#ft_read_and_stash)
		- [ft_extract_line](#ft_extract_line)
		- [ft_clean_stash](#ft_clean_stash)
2. [Instructions](#instructions)
	- [Compilation](#compilation)
		- [Basic](#basic)
		- [Customized](#customized)
3. [Resources](#resources)

## Description
The goal of **get_next_line** is to write a function in C that reads a line from a File Descriptor (fd), one line at a time, until the end of the file (EOF)

## Algorithm and Technical Choices
The algorithm uses a single static variable called `stash`to keep data between function calls.
The code checks every `malloc` and `read` return value and if any allocations fails, it `free()` all active pointers too prevent any memory leak and SEGFAULTS.
To be efficient, the code stops reading the file as soon as a `\n` is meet, as requested in the subject.
#### ft_read_and_stash: 
Function which reads from the fd blocks of BUFFER-SIZE and joins them to the static by using `ft_strdup` or `ft_strjoin`. It stops when a new line is found or EOF is reached.
#### ft_extract_line: 
It finds the first `\n`, allocates memory for the line, and copies the character.
#### ft_clean_stash: 
It removes the returned line from `stash` and saves the remaining text for the next call.

## Instructions
### Compilation
The project compile with the `-Wall`, `-Wextra`, `-Werror` flags.
Also, you can edit the buffer size value with `-D BUFFER_SIZE=<your value>` so it will read the file with a customised size instead of the original one defined in the .h.
#### Basic
Here's an example with the BUFFER_SIZE value i put in my .h:
```bash 
cc -Wall -Wextra -Werror get_next_line.h get_next_line.c get_next_line_utils.c main.c
```
#### Customized
Here's an example with BUFFER_SIZE=42
```bash 
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl 
```

## Resources
To help me with the project, I watched a video about GNL on Youtube [comprendre get_next_line](https://youtu.be/-Mt2FdJjVno?si=1Cj6KBUezWmPeFit) and looked at some documentation about how to use static variable [static-variable-in-c](#https://www.geeksforgeeks.org/c/static-variables-in-c/)