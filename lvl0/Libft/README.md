## Grade

| **Score**           | **Description**     |
|-----------------------|---------------|
| <p align="center"><img width="222px" alt="170px" src="./img/Score_125.png"></p> | **Mandatory part + Full bonus part**   |


## Libft

I developed a personal library in C called libft, which includes a collection of essential functions inspired by those in the standard C library (libc). This project involves re-implementing common libc functions and additional utility functions to understand their inner workings and to create a reusable library for future projects.


## Instruction set


To meet the objectives of the mandatory part of the project, the following rules must be followed:

| **#** | **Instruction**                                                                                                                                                         |
| ----- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
|  `1`  | **Code and Standards:** The project must be written in C and adhere to the specified coding standards. Any deviation will result in a zero score.                          
|  `2`  | **Function Implementation:** Implement specified libc functions with the same prototypes and behaviors, but with the prefix ft_. Do not include the restrict keyword or compile with -std=c99.                                 |
|  `3`  | **Memory Management:** Properly manage all allocated memory to avoid memory leaks. Use malloc() where necessary.                                                          |
|  `4`  | **Error Handling:** Functions must not cause unexpected crashes (e.g., segmentation faults, bus errors, double frees) or exhibit undefined behavior.                      |
|  `5`  | **Makefile:** Provide a Makefile with at least the rules $(NAME), all, clean, fclean, and re. It should compile all .c files with -Wall, -Werror, and -Wextra flags and create a libft.a library at the root of the repository. |
|  `6`  | **Prohibited Elements:** Do not declare global variables. Separate complex functions into static functions within the appropriate file. Do not submit unused files.       |
|  `7`  | **Function Set:** Re-implement the specified libc functions, such as isalpha, isdigit, strlen, memset, memcpy, strdup, etc., with their corresponding ft_ prefixed names. |


## Functions of the mandatory part

**Replicate original functions:**

| **Function** | **Description**                                                                                                                                  |
| ------------ | ------------------------------------------------------------------------------------------------------------------------------------------------ |
| [**isalpha**](ft_isalpha.c) | Checks if a character is an alphabetic letter.                                                                                                   |
| [**isdigit**](ft_isdigit.c) | Checks if a character is a numeric digit.                                                                                                        |
| [**isalnum**](ft_isalnum.c) | Checks whether a character is alphanumeric, that is, a letter or a digit.                                                                        |
| [**isascii**](ft_isascii.c) | Checks whether an integer value represents a valid ASCII character (between 0 and 127).                                                          |
| [**isprint**](ft_isprint.c) | Checks whether a character is printable (visible) and belongs to the ASCII printable character set.                                              |
| [**strlen**](ft_strlen.c) | Calculates the length of a character string (not including the null character).                                                                  |
| [**memset**](ft_memset.c) | Fills a block of memory with a specific value.                                                                                                   |
| [**bzero**](ft_bzero.c) | Obsolete. It is similar to memset but is used to set a block of memory to zero.                                                                  |
| [**memcpy**](ft_memcpy.c) | Copies a block of memory from a source location to a destination location.                                                                       |
| [**memmove**](ft_memmove.c) | Copies a block of memory from a source location to a destination location, handling memory overlays.                                             |
| [**strlcpy**](ft_strlcpy.c) | Copies a string to a buffer with a maximum limit, avoiding buffer overflows.                                                                     |
| [**strlcat**](ft_strlcat.c) | Concatenates two strings to a buffer with a maximum limit, avoiding buffer overflows.                                                            |
| [**toupper**](ft_toupper.c) | Converts a lowercase character to uppercase, if applicable.                                                                                      |
| [**tolower**](ft_tolower.c) | Converts an uppercase character to lowercase, if applicable.                                                                                     |
| [**strchr**](ft_strchr.c) | Finds the first occurrence of a character in a string.                                                                                           |
| [**strrchr**](ft_strrchr.c) | Finds the last occurrence of a character in a string.                                                                                            |
| [**strncmp**](ft_strncmp.c) | Compares the first n characters of two strings.                                                                                                  |
| [**memchr**](ft_memchr.c) | Finds the first occurrence of a specific byte in a block of memory.                                                                              |
| [**memcmp**](ft_memcmp.c) | Compares the first n bytes of two blocks of memory.                                                                                              |
| [**strnstr**](ft_strnstr.c) | Finds the first occurrence of a substring in a string, up to a maximum number of characters.                                                     |
| [**atoi**](ft_atoi.c) | Converts a character string representing a number to an integer (int).                                                                           |
| [**calloc**](ft_calloc.c) | Dynamically allocates a block of memory for a specified number of elements, initializing each byte to zero.                                      |
| [**strdup**](ft_strdup.c) | Duplicates a string of characters to a new memory location, dynamically allocating enough space and copying the contents of the original string. |

**Additional functions:**

|  **Function**   | **Description**                                                                                                                            |
| --------------- | ------------------------------------------------------------------------------------------------------------------------------------------ |
| [**substr**](ft_substr.c) | Reserve (with malloc(3)) and return a substring of the string 's'. The substring starts from index 'start' and has a length of max. 'len'. |
| [**strjoin**](ft_strjoin.c) | Reserve (with malloc(3)) and return a new string, formed by the concatenation of 's1' and 's2'.                                            |
| [**strtrim**](ft_strtrim.c) | Removes all characters from the string 'set' from the beginning and end of 's1', until a character not belonging to 'set' is found. The resulting string is returned with a malloc(3) fallback. |
| [**split**](ft_split.c) | Reserve (using malloc(3)) an array of strings resulting from separating the string 's' into substrings using the character 'c' as a delimiter. The array must be terminated with a NULL pointer. |
| [**itoa**](ft_itoa.c) | Using malloc(3), generate a string that represents the integer value received as an argument. Negative numbers have to be managed.         |
| [**strmapi**](ft_strmapi.c) | To each character of the string 's', apply the function 'f' giving as parameters the index of each character within 's' and the character itself. Generates a new string with the result of successive use of 'f' |
| [**striteri**](ft_striteri.c) | To each character of the string 's', apply the function 'f' giving as parameters the index of each character within 's' and the address of the character itself, which can be modified if necessary. |
| [**putchar_fd**](ft_putchar_fd.c) | Sends the character 'c' to the specified file descriptor.                                                                                  |
| [**putstr_fd**](ft_putstr_fd.c) | Sends the string 's' to the specified file descriptor.                                                                                     |
| [**putendl_fd**](ft_putendl_fd.c) | Sends the string 's' to the given file descriptor, followed by a line break.                                                               |
| [**putnbr_fd**](ft_putnbr_fd.c) | Sends the number 'n' to the given file descriptor.                                                                                         |

## The Bonus part

<p>To fully complete the bonus part of the project, the following conditions must be met:</p>

| **#** | **Instruction**                                                                                                                                                                 |
| ----- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
|  `1`  | **Complete Mandatory Part:** The mandatory part of the project must be fully completed and meet all specified requirements.                                                     |
|  `2`  | **Additional Functions:** Implement the additional functions specified for the bonus section. These functions involve manipulating linked lists.                                |
|  `3`  | **Separate Files:** The bonus functions should be implemented in separate files, typically named with _bonus suffixes (e.g., ft_lstnew_bonus.c, ft_lstadd_front_bonus.c, etc.). |
|  `4`  | **Comprehensive Testing:** Ensure that the bonus functions are tested thoroughly and work correctly under various conditions and edge cases.                                    |

## Functions of the bonus part

| **Function**      | **Description**                                                                                                                                              |
| ----------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| [**lstnew**](ft_lstnew_bonus.c) | Create a new node using malloc(3). The member variable 'content' is initialized with the content of the parameter 'content'. The 'next' variable, with NULL. |
| [**lstadd_front**](ft_lstadd_front_bonus.c) | Add the 'new' node to the beginning of the 'lst' list.                                                                                                       |
| [**lstsize**](ft_lstsize_bonus.c) | Counts the number of nodes in a list.                                                                                                                        |
| [**lstlast**](ft_lstlast_bonus.c) | Returns the last node in the list.                                                                                                                           |
| [**lstadd_back**](ft_lstadd_back_bonus.c) | Add the 'new' node to the end of the 'lst' list.                                                                                                             |
| [**lstdelone**](ft_lstdelone_bonus.c) | It takes as a parameter a node 'lst' and frees the memory of the content using the function 'del' given as a parameter, in addition to freeing the node. The 'next' memory must not be freed. |
| [**lstclear**](ft_lstclear_bonus.c) | Delete and free the given ’lst’ node and all consecutive nodes of that node, using the ’del’ and free(3) function. In the end, the pointer to the list must be NULL. |
| [**lstiter**](ft_lstiter_bonus.c) | Iterates the list 'lst' and applies the function 'f' on the content of each node.                                                                            |
| [**lstmap**](ft_lstmap_bonus.c) | Iterates the list 'lst' and applies the function 'f' to the contents of each node. Creates a list resulting from the correct and successive application of the function 'f' on each node. The 'del' function is used to delete the contents of a node, if necessary. |