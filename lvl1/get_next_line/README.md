## Grade

| **Score**           | **Description**     |
|-----------------------|---------------|
| <p align="center"><img width="200px" alt="170px" src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl1/printf/img/Score_100.png"></p> | **Mandatory part**   |


## get_next_line

I developed a function in C called get_next_line that reads and returns a line from a given file descriptor. This project involves handling static variables and ensuring proper memory management while avoiding common pitfalls like segmentation faults or memory leaks. The implementation supports both regular and bonus features, including handling multiple file descriptors simultaneously.


## Instruction set


To meet the objectives of the mandatory part of the project, the following rules must be followed:

| **#** | **Instruction**                                                                                                                                                            |
| ----- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
|  `1`  | **Language and Standards:** The project must be written in C and follow the specified coding standards. Any deviations will result in a score of zero.                     |
|  `2`  | **Function Requirements:** Implement a function get_next_line that reads and returns a line from a given file descriptor. It should return NULL if an error occurs or if the end of the file is reached.                                                                                                                                                              |
|  `3`  | **Memory Management:** All allocated memory must be freed appropriately to avoid memory leaks.                                                                             |
|  `4`  | **Error Handling:** Functions must not crash (e.g., no segmentation faults, bus errors, or double frees). Undefined behavior is not allowed.                               |
|  `5`  | **Makefile:** Provide a Makefile that compiles the project with -Wall, -Werror, and -Wextra flags. The Makefile should have rules for $(NAME), all, clean, fclean, and re. |
|  `6`  | **Buffer Size:** The program must compile with and without the -D BUFFER_SIZE=xx flag, which determines the buffer size for reading.                                       |
|  `7`  | **Prohibited:** Usage of libft, lseek, and global variables is not allowed.                                                                                                |
|  `8`  | **Static Variables:** Proper use of static variables in the implementation is required.                                                                                    |


## Preview of the mandatory part



## The Bonus part

<p>To fully complete the bonus part of the project, the following conditions must be met:</p>

| **#** | **Instruction**                                                                                                                                                       |
| ----- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
|  `1`  | **Complete Mandatory Part:** The mandatory part of the project must be completed perfectly, meaning all requirements are met and the implementation works flawlessly. |
|  `2`  | **Single Static Variable:** Implement get_next_line using only one static variable.                                                                                   |
|  `3`  | **Multiple File Descriptors:** The function must handle multiple file descriptors at once. For example, it should be able to read from file descriptors 3, 4, and 5 alternately without losing the reading position of each.                                                                                                                                    |
|  `4`  | **Separate Bonus Files:** The bonus implementation should be in separate files named get_next_line_bonus.c, get_next_line_bonus.h, and get_next_line_utils_bonus.c.   |