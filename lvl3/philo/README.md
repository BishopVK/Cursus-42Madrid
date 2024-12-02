## Grade

| **Score**           | **Description**     |
|-----------------------|---------------|
| <p align="center"><img width="200px" alt="170px" src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl3/philo/img/Score_108.png"></p> | **Mandatory part**   |


## Philosophers

The project (mandatory part) involves simulating the "Dining Philosophers" problem using threads and mutexes in C. Each philosopher is represented as a thread, and there is a fork between each pair of philosophers. The simulation requires that each philosopher must pick up the fork on their left and right to eat, and they cannot eat, think, or sleep simultaneously. The goal is to ensure that all philosophers can eat without deadlock or starvation, while properly managing the state of the forks using mutexes to prevent concurrent access.


## Instruction set

Here is a list of instructions required to complete the project::

| **#** | **Instruction** |
| ----- | --------------- |
|  `1`  | Write a program for the mandatory part and another for the bonus part (if you choose to do the bonus). |
|  `2`  | Global variables are prohibited. |
|  `3`  | The program(s) must accept the following arguments: |
|       | `number_of_philosophers:` the number of philosophers (and also the number of forks). |
|       | `time_to_die (in milliseconds):` the time after which a philosopher dies if they do not start eating |
|       | `time_to_eat (in milliseconds):` the time a philosopher has to eat. |
|       | `time_to_sleep (in milliseconds):` the time a philosopher has to sleep. |
|       | `number_of_times_each_philosopher_must_eat (optional):` if specified, the simulation stops when all philosophers have eaten this number of times; otherwise, it stops when a philosopher dies. |
|  `4`  | Each philosopher must be assigned a number from 1 to number_of_philosophers. |
|  `5`  | The program must ensure that philosophers do not starve and avoid deadlock situations. |
|  `6`  | Use appropriate synchronization mechanisms (mutexes for the mandatory part and semaphores for the bonus part) to manage access to shared resources (forks). |


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