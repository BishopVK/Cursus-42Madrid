## Grade

| **Score**           | **Description**     |
|-----------------------|---------------|
| <p align="center"><img width="200px" alt="170px" src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl2/so_long/img/Score_125.png"></p> | **Mandatory part + full bonus part**   |


## so_long

Get ready to dive into the world of SoLong! This project invites you to explore the realm of 2D gaming by working with textures, sprites, and fundamental gameplay elements. Unleash your creativity and craft your very own virtual universe!


## Instruction set

To meet the objectives of the mandatory part of the project, I had to follow these rules:

| **#** | **Instruction**                                                                                 |
| ----- | ----------------------------------------------------------------------------------------------- |
|  `1`  | Collect all objects on the map and choose the shortest route                                    |
|  `2`  | Use W, A, S, and D keys to move the main character                                              |
|  `3`  | Move the character in four directions: up, down, left, or right                                 |
|  `4`  | Avoid entering walls                                                                            |
|  `5`  | Display the real number of movements after each move in a terminal.                             |
|  `6`  | Utilize a 2D perspective (bird's-eye view or side view).                                        |
|  `7`  | The game does not need to be real-time.                                                         |
|  `8`  | Ensure clean window management, including switching windows and minimizing.                     |
|  `9`  | Pressing ESC should close the window and end the program cleanly.                               |
|  `10` | Clicking the red cross on the window should close the window and terminate the program cleanly. |


## Preview of the mandatory part

<p align="center">
<img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl2/so_long/img/map_mandatory.gif">
</p>


## Flood Fill

<p>The flood fill function is an algorithm used to determine and alter the area connected to a given node in a multi-dimensional array. It's commonly used in computer graphics to fill contiguous regions with a color or pattern, such as filling a bounded area in a paint program. The algorithm works by starting from a target node, checking adjacent nodes, and spreading outwards to all nodes that match the initial condition, replacing them with a new value.</p>

<p>In this project, the flood fill function has been used to check the solvability of the maps.</p>
<p>Starting from the player's position (P), the entire map is traversed while avoiding walls (1), and enemies (K) in the bonus part, to ensure that the player can reach all the collectibles (C) and the exit (E). If not, the map will be unsolvable.</p>

<p>Demonstration of the flood fill function in action:</p>
<p align="left">
<img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl2/so_long/img/Flood_fill.gif">
</p>


## The Bonus part

<p>To fully pass the bonus part, I need to ensure the following conditions are met:</p>

| **#** | **Instruction**                                                                             |
| ----- | ------------------------------------------------------------------------------------------- |
|  `1`  | The mandatory part must be PERFECT, functioning correctly with impeccable error management. |
|  `2`  | Additional functionalities: losing when touching enemy patrols.                             |
|  `3`  | Additional functionalities: added sprite animations.                                        |
|  `4`  | Additional functionalities: displayed the movement counter directly on the screen.          |


## Preview of the bonus part

<p align="center">
<img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl2/so_long/img/map_bonus.gif">
</p>