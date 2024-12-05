## Grade

| **Score**           | **Description**     |
|-----------------------|---------------|
| <p align="center"><img width="200px" alt="170px" src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl4/exam_rank_04/img/Score_100.png"></p> | **Full complete exam** |


## Exam Rank 04

The exam rank 04 consists exclusively of completing one exercise: **microshell.** This exercise implements a basic shell-like command executor in C. It parses and executes commands provided as arguments, supporting command pipelines (|) and sequences (;). The built-in cd command is implemented with strict error handling. It focuses on low-level system programming using system calls like fork, pipe, execve, and chdir, with robust error management for invalid inputs or system call failures.


## Key features and constraints include

* **Command Execution:**
  * Accepts commands as arguments, with the executable's path provided as absolute or relative.
  * The program does not build paths using the `PATH` environment variable.

* **Built-in** `cd` **Command:**
  * Handles directory changes with a single argument (the path).
  * Prints appropriate error messages to `STDERR` if the arguments are invalid or the directory change fails.

* **Special Symbols:**
  * Supports `|` for piping commands and `;` for separating commands.
  * Does not allow invalid symbol usage, such as consecutive or misplaced `|` or `;`.

* **Error Handling:**
  * Prints `error: fatal` to `STDERR` and exits immediately if any system call (other than `execve` and `chdir`) fails.
  * Prints `error: cannot execute executable` if `execve` fails.

* **Scalability:**
  * Capable of handling large numbers of pipes (`|`), even with a limited number of open files (e.g., less than 30).


## What This Project Does Not Manage
* Wildcards (e.g., `*`, `~`).
* Environment variable expansion (e.g., `$BLA`).


## Instruction set

To pass this exam, you must successfully complete the exercise. If done correctly, you will receive a score of 100 out of 100 points. The exam procedure is as follows:

| **#** | **Instruction**                                                                                                                                                         |
| ----- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
|  `1`  | **Duration:** You have a maximum of 3 hours to complete the exam. |
|  `2`  | **Access to the repository:** Upon successfully logging in, you will have access to a repository where you must create a directory and upload exclusively the files for each exercise. |
|  `3`  | **Access to the subject:** When you start or pass an exercise, you will find the subject available in the "subject" folder, containing the exercise statement and its rules. |
|  `4`  | **Grademe:** After completing and uploading the exercise to the correct directory in the repository, you must type the keyword "grademe". The exercise will be analyzed, and if correct, you will pass the level and receive 100 points. |
|  `5`  | **Completion of the exam:** The exam ends when you successfully complete the exercise. Otherwise, you can correct the errors and resubmit it until you pass or the maximum time of 3 hours is exhausted. |



## My exam

You can see how i solved it below:

| **#** | **Exercise**                                         |
| ----- | ---------------------------------------------------- |
|  `1`  | [**microshell.c:**](/lvl4/exam_rank_04/microshell.c) |
|  `2`  | [**microshell.h:**](/lvl4/exam_rank_04/microshell.h) |