## Grade

| **Score** | **Description** |
| --------- | ----- |
| <p align="center"><img width="200px" alt="170px" src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl3/Philosophers/img/Score_108.png"></p> | **Mandatory part**   |


## Philosophers

The project (mandatory part) involves simulating the "Dining Philosophers" problem using threads and mutexes in C. Each philosopher is represented as a thread, and there is a fork between each pair of philosophers. The simulation requires that each philosopher must pick up the fork on their left and right to eat, and they cannot eat, think, or sleep simultaneously. The goal is to ensure that all philosophers can eat without deadlock or starvation, while properly managing the state of the forks using mutexes to prevent concurrent access.


## Instruction set

Here is a list of instructions required to complete the project:

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

In this image, one can observe a scenario where the philosophers have an appropriate amount of time to organize themselves and eat, sleep, and think without dying at any point.

<p align="center">
<img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl3/Philosophers/img/preview.png">
</p>

In this other case, it is evident that the timing was very tight, resulting in one of the philosophers dying due to not being able to eat. Their death was announced with zero milliseconds of delay from the moment the thread died and was printed.

<p align="center">
<img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl3/Philosophers/img/preview_2.png">
</p>