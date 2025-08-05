## Grade

| **Score**           | **Description**     |
|---------------------|---------------------|
| <p align="center"><img width="200px" alt="Score 100" src="./img/Score_100.png"></p> | **Full complete exam** |


## Exam Rank 06

The exam rank 06 consists of a single exercise: **mini_serv**. The goal is to implement a simple chat server in C that allows multiple clients to connect, exchange messages, and receive system notifications when other users connect or disconnect. This project emphasizes **event-driven programming** using `select()` and non-blocking I/O.

## Key features and constraints include

* **Socket Programming Basics:**
  * The server binds to `127.0.0.1` on a port provided as the first argument.
  * If no port is provided, it prints `"Wrong number of arguments"` to `STDERR` and exits with status `1`.
  * On any system call failure (before accepting connections), or if memory allocation fails, it prints `"Fatal error"` and exits with status `1`.

* **Client Handling:**
  * Each new client gets a unique ID starting from `0`, incremented sequentially.
  * When a client connects, the server sends:  
    `server: client %d just arrived\n` to all other connected clients.
  * When a client disconnects, the server sends:  
    `server: client %d just left\n`.

* **Message Broadcasting:**
  * Clients can send messages containing printable characters (including multiple `\n`).
  * Each line of the received message must be prefixed and broadcast as:  
    `client %d: <line>\n` to all other clients.

* **Technical Requirements:**
  * The program must be **non-blocking** and use `select()` to handle I/O.
  * It must **not** use `#define` macros.
  * It must **not** read/write to `stdin` or `stdout`.
  * No file descriptor or memory leaks are allowed.
  * Avoid unnecessary buffering or delays — send data **immediately**.

* **Hints & Tools:**
  * You can use `nc` (netcat) to test the server:  
    Example: `nc 127.0.0.1 <port>`
  * `fcntl(fd, F_SETFL, O_NONBLOCK)` is useful for testing,  
    but the correct logic must rely on `select()`.

## What This Project Does Not Handle

* Authentication or encryption.
* Message history or command parsing.
* Named users or nickname changes.

## Instruction set

| **#** | **Instruction**                                                                                                                                                         |
| ----- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
|  `1`  | **Duration:** You have a maximum of 3 hours to complete the exam. |
|  `2`  | **Access to the repository:** After login, you'll access a repository where you must create a directory and upload only the required files. |
|  `3`  | **Access to the subject:** The exercise description is available inside the "subject" folder. |
|  `4`  | **Grademe:** After uploading your solution to the proper directory, run the command `grademe` to trigger automatic correction. |
|  `5`  | **Completion:** The exam finishes once you pass the exercise or run out of time. Resubmissions are allowed within the time limit. |


## My exam

You can see how I solved it below:

| **#** | **Exercise**                                        |
| ----- | --------------------------------------------------- |
|  `1`  | [**mini_serv.c**](mini_serv.c)   |
