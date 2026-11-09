*This project has been created as part of the 42 curriculum by mbardeau.*
# GET-NEXT-LINE  (GNL) - 42 Project

## Description
The goal of **get_next_line** is to write a function in C that reads a line from a File Descriptor (fd), one line at a time, until the end of the file (EOF)

## Algorithm Explanation
The algorithm uses a single static variable called `stash`to keep data between function calls.
**ft_read_and_stash**: Function which reads from the fd blocks of BUFFER-SIZE and joins them to the static by using `ft_strdup` or `ft_strjoin`. It stops when a new line is found or EOF is reached.
**ft_extract_line**: It finds the first `\n`, allocates memory for the line, and copies the character.
**clean_stash**: It removes the returned line from `stash` and saves the remaining text for the next call.