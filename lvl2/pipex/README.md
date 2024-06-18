## Grade

| **Score**           | **Description**     |
|-----------------------|---------------|
| <p align="center"><img width="200px" alt="170px" src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl2/pipex/img/Score_125.png"></p> | **Mandatory part + full bonus part**   |


## pipex

In this project, Pipex, I delve into the workings of a familiar UNIX mechanism by developing a program that mimics the behavior of shell commands using pipes. By handling input and output redirection, executing multiple commands in sequence, and managing errors meticulously, I aim to enhance my understanding of low-level system operations and strengthen my programming skills in C.


## Instruction set

To fulfill the objectives of the mandatory part of the project Pipex, the following rules must be adhered to:

| **#** | **Instruction**                                                                                                                                                |
| ----- | -------------------------------------------------------------------------------------------------------------------------------------------------------------- |
|  `1`  | Develop a program named "pipex" that emulates the functionality of shell commands using pipes.                                                                 |
|  `2`  | The program should be executed with four arguments: input file, first command, second command, and output file.                                                |
|  `3`  | Manage errors diligently to prevent unexpected program termination.                                                                                            |
|  `4`  | Ensure no memory leaks occur during program execution.                                                                                                         |
|  `5`  | Implement the program to replicate the behavior of the command "< file1 cmd1 | cmd2 > file2".                                                                  |
|  `6`  | Utilize authorized functions: open, close, read, write, malloc, free, perror, strerror, access, dup, dup2, execve, exit, fork, pipe, unlink, wait and waitpid. |
|  `7`  | Deliver essential files including Makefile, header files, and source files for evaluation.                                                                     |


## Preview of the mandatory part

In this case, we read the contents of Martin_Luther_King.txt. The cat command is responsible for reading the received content. Through the pipe we pass the result to the awk command, which in this case is responsible for printing the fourth column of each row of text, and passing the output to the standard output.

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