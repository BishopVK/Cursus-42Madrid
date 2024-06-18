## Grade

| **Score**           | **Description**     |
|-----------------------|---------------|
| <p align="center"><img width="200px" alt="170px" src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl1/printf/img/Score_100.png"></p> | **Mandatory part**   |


## ft_printf

I am working on a project to reprogram the printf() function in C. This involves creating a custom version called ft_printf() that can handle various data types and formatting options. The project requires the use of variadic functions to manage a variable number of arguments, and it focuses on developing a well-structured and extensible codebase. The final implementation will include support for different conversions such as characters, strings, integers, and hexadecimals, mimicking the original printf() functionality. This project is an opportunity to enhance my C programming skills and will be added to my libft for use in future C projects.


## Instruction set


To meet the objectives of the mandatory part of the project, the following rules must be followed:

| **#** | **Instruction**                                                                                                                                                         |
| ----- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
|  `1`  | The project must be written in C and follow the Norm (coding standards).                                                                                                |
|  `2`  | Functions must not cause unexpected crashes (segfaults, bus errors, double frees) or undefined behavior.                                                                |
|  `3`  | All heap-allocated memory must be properly freed to avoid memory leaks.                                                                                                 |
|  `4`  | A Makefile must be provided to compile the source files with the flags -Wall, -Werror, and -Wextra, and it must include the rules: $(NAME), all, clean, fclean, and re. |
|  `5`  | If the project allows using libft, its source and Makefile should be included in a libft directory. The Makefile should compile libft first and then the project.       |
|  `6`  | The ft_printf() function must implement the following conversions: %c, %s, %p, %d, %i, %u, %x, %X, and %%.                                                              |
|  `7`  | The project must not implement the buffer management of the original printf().                                                                                          |
|  `8`  | The ft_printf() function will be compared to the original printf() for correctness.                                                                                     |
|  `9`  | The ar command must be used to create the libftprintf.a library, and libtool is not allowed.                                                                            |


## Preview of the mandatory part

| Conversion  | Code                         | Result                                                 |
| ----------- | ----------------------------------- | ------------------------------------------------------ |
|    `%c`     | <p align="center"><img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl1/printf/img/char_code.png"></p> | <p align="center"><img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl1/printf/img/char_result.png"></p> |
|    `%c`     | <p align="center"><img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl1/printf/img/char_code.png"></p> | <p align="center"><img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl1/printf/img/char_result.png"></p> |
|    `%c`     | <p align="center"><img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl1/printf/img/char_code.png"></p> | <p align="center"><img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl1/printf/img/char_result.png"></p> |
|    `%c`     | <p align="center"><img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl1/printf/img/char_code.png"></p> | <p align="center"><img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl1/printf/img/char_result.png"></p> |
|    `%c`     | <p align="center"><img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl1/printf/img/char_code.png"></p> | <p align="center"><img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl1/printf/img/char_result.png"></p> |
|    `%d`     | swap b                              | swaps the 2 top elements of stack b                    |
|    `%i`     | swap a + swap b                     | both `sa` and `sb`                                     |
|    `%%`     | push a                              | moves the top element of stack b at the top of stack a |
|    `%u`     | push b                              | moves the top element of stack a at the top of stack b |
| `ra`  | rotate a                            | shifts all elements of stack a from bottom to top      |
| `rb`  | rotate b                            | shifts all elements of stack b from bottom to top      |
| `rr`  | rotate a + rotate b                 | both `ra` and `rb`                                     |
| `rra` | reverse rotate a                    | shifts all elements of stack a from top to bottom      |
| `rrb` | reverse rotate b                    | shifts all elements of stack b from top to bottom      |
| `rrr` | reverse rotate a + reverse rotate b | both `rra` and `rrb`                                   |



<p align="center">
<img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl2/pipex/img/awk.png">
</p>


## The Bonus part

<p>To fully pass the bonus part of the project Pipex, the following conditions must be met:</p>

| **#** | **Instruction**                                                                                                                        |
| ----- | -------------------------------------------------------------------------------------------------------------------------------------- |
|  `1`  | Implement the ability to handle multiple pipes in the program..                                                                        |
|  `2`  | Support input redirection using "<< LIMITER" and output redirection using ">>" when the first parameter is "here_doc".                 |
|  `3`  | Ensure that the mandatory part of the project is flawless without any errors, even in extreme or misuse cases.                         |
|  `4`  | Bonus features will only be evaluated if the mandatory part is deemed perfect; otherwise, the bonus will be ignored during assessment. |


## Preview of the bonus part

**Multiple pipes:**
<br>
<br>
In this case, we read the content of infile.txt. The "cat" command is responsible for reading the received content. "ls -la" will ignore the input received and list directories and files in the current path including hidden files. "awk" will filter out the ninth column from the result, which includes the names of the files and directories. "grep pipex" will exclude from the final result anything that does not contain the word "pipex". Finally and for convenience for this example, we show the result through the output to the standard output.

<p align="center">
<img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl2/pipex/img/bonus.png">
</p>
<br>


**Here doc:**
<br>
<br>
In this second case we simulate the use of the here doc.
To do this we use the reserved word "here_doc" followed by the reserved word for escaping the here doc, in this case EOF.
We will enter the desired text through standard input, which will stop automatically when the escape word is detected. "grep rose" will filter out all received lines that contain the word "rose". "wc -w" will count the number of words in the received line. The result will be stored with an append in the file outfile.txt, adding the result to the end of the document. In this case 4: the number of words contained in the line "A rose by anyone".

<p align="center">
<img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl2/pipex/img/here_doc.png">
</p>