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
|    `%c`     | <p align="left"><img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl1/printf/img/char_code.png"></p> | <p align="left"><img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl1/printf/img/char_result.png"></p> |
|    `%d`     | <p align="left"><img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl1/printf/img/integer_d_code.png"></p> | <p align="left"><img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl1/printf/img/integer_d_result.png"></p> |
|    `%i`     | <p align="left"><img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl1/printf/img/integer_i_code.png"></p> | <p align="left"><img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl1/printf/img/integer_i_result.png"></p> |
|    `%%`     | <p align="left"><img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl1/printf/img/percentage_code.png"></p> | <p align="left"><img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl1/printf/img/percentage_result.png"></p> |
|    `%u`     | <p align="left"><img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl1/printf/img/unsigned_int_code.png"></p> | <p align="left"><img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl1/printf/img/unsigned_int_result.png"></p> |
|    `%s`     | <p align="left"><img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl1/printf/img/string_code.png"></p> | <p align="left"><img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl1/printf/img/string_result.png"></p> |
|    `%s`     | <p align="left"><img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl1/printf/img/string_null_code.png"></p> | <p align="left"><img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl1/printf/img/string_null_result.png"></p> |
|`not printable` | <p align="left"><img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl1/printf/img/not_printable_code.png"></p> | <p align="left"><img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl1/printf/img/not_printable_result.png"></p> |
|    `%x`     | <p align="left"><img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl1/printf/img/lowercase_hexadecimal_code.png"></p> | <p align="left"><img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl1/printf/img/lowercase_hexadecimal_result.png"></p> |
|    `%X`     | <p align="left"><img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl1/printf/img/uppercase_hexadecimal_code.png"></p> | <p align="left"><img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl1/printf/img/uppercase_hexadecimal_result.png"></p> |
|    `%p`     | <p align="left"><img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl1/printf/img/pointer_code.png"></p> | <p align="left"><img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl1/printf/img/pointer_result.png"></p> |
|    `%p`     | <p align="left"><img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl1/printf/img/pointer_void_code.png"></p> | <p align="left"><img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl1/printf/img/pointer_void_result.png"></p> |
| `Multiple conversions`  | <p align="left"><img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl1/printf/img/multiple_code.png"></p> | <p align="left"><img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl1/printf/img/multiple_result.png"></p> |


## The Bonus part

<p>To fully complete the bonus part of the project, the following conditions must be met:</p>

| **#** | **Instruction**                                                                                                                                        |
| ----- | ------------------------------------------------------------------------------------------------------------------------------------------------------ |
|  `1`  | **Bonus Implementation:** Implement any combination of the following flags: '-0.' and the field minimum width for all possible conversions.            |
|  `2`  | **Additional Flags:** Handle all of the following flags: '# +' (including the space).                                                                  |
|  `3`  | **Perfect Mandatory Part:** The mandatory part of the project must be perfect, meaning it works completely without any errors or unexpected behaviors. |
|  `4`  | **Separate Files:** Bonus features must be implemented in separate files named _bonus.{c/h}.                                                           |
|  `5`  | **Makefile Rule:** Include a bonus rule in the Makefile that compiles these bonus features.                                                            |