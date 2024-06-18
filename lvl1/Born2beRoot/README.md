## Grade

| **Score**           | **Description**     |
|-----------------------|---------------|
| <p align="center"><img width="222px" alt="170px" src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl1/Born2beRoot/img/Score_125.png"></p> | **Mandatory part + Full bonus part**   |


## Born2beRoot

I set up my first server using virtualization with VirtualBox. This project involved configuring the server with a minimal number of services, implementing strong password policies, and setting up SSH and firewall rules. Additionally, I created a monitoring script to display system information periodically. The objective was to learn the fundamentals of system administration and ensure the server operates securely and efficiently.


## Instruction set


To meet the objectives of the mandatory part of the project, the following rules must be followed:

| **#** | **Instruction**                                                                                                                                                           |
| ----- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
|  `1`  | **Virtualization:** Use VirtualBox (or UTM if VirtualBox is not available) to create your virtual machine. |
|  `2`  | **Operating System:** Install the latest stable version of Debian or Rocky Linux (Debian is recommended for beginners). |
|  `3`  | **Minimal Services:** Configure the server with the minimal number of services. Do not install any graphical interface like X.org. |
|  `4`  | **SSH Configuration:** 
* SSH must run on port 4242 only. 
* Root login via SSH should be disabled. 
* Use SSH to create a new user during the defense. |
|  `5`  | **Firewall Configuration:** 
* Use UFW (or firewalld for Rocky) to configure the firewall, allowing only port 4242. 
* The firewall must be active when the virtual machine runs. |
|  `6`  | **Hostname:** Set the hostname of the virtual machine to your login followed by "42" (e.g., wil42). |
|  `7`  | **User and Groups:** 
* Create a user with your login name. 
* This user must belong to the groups user42 and sudo. 
* Implement a strong password policy for all users. |


## Functions of the mandatory part

**Replicate original functions:**

| **Function** | **Description**                                                                                                                                  |
| ------------ | ------------------------------------------------------------------------------------------------------------------------------------------------ |
|   `isalpha`  | Checks if a character is an alphabetic letter.                                                                                                   |
|   `isdigit`  | Checks if a character is a numeric digit.                                                                                                        |
|   `isalnum`  | Checks whether a character is alphanumeric, that is, a letter or a digit.                                                                        |
|   `isascii`  | Checks whether an integer value represents a valid ASCII character (between 0 and 127).                                                          |
|   `isprint`  | Checks whether a character is printable (visible) and belongs to the ASCII printable character set.                                              |
|   `strlen`   | Calculates the length of a character string (not including the null character).                                                                  |
|   `memset`   | Fills a block of memory with a specific value.                                                                                                   |
|   `bzero`    | Obsolete. It is similar to memset but is used to set a block of memory to zero.                                                                  |
|   `memcpy`   | Copies a block of memory from a source location to a destination location.                                                                       |
|   `memmove`  | Copies a block of memory from a source location to a destination location, handling memory overlays.                                             |
|   `strlcpy`  | Copies a string to a buffer with a maximum limit, avoiding buffer overflows.                                                                     |
|   `strlcat`  | Concatenates two strings to a buffer with a maximum limit, avoiding buffer overflows.                                                            |
|   `toupper`  | Converts a lowercase character to uppercase, if applicable.                                                                                      |
|   `tolower`  | Converts an uppercase character to lowercase, if applicable.                                                                                     |
|   `strchr`   | Finds the first occurrence of a character in a string.                                                                                           |
|   `strrchr`  | Finds the last occurrence of a character in a string.                                                                                            |
|   `strncmp`  | Compares the first n characters of two strings.                                                                                                  |
|   `memchr`   | Finds the first occurrence of a specific byte in a block of memory.                                                                              |
|   `memcmp`   | Compares the first n bytes of two blocks of memory.                                                                                              |
|   `strnstr`  | Finds the first occurrence of a substring in a string, up to a maximum number of characters.                                                     |
|   `atoi`     | Converts a character string representing a number to an integer (int).                                                                           |
|   `calloc`   | Dynamically allocates a block of memory for a specified number of elements, initializing each byte to zero.                                      |
|   `strdup`   | Duplicates a string of characters to a new memory location, dynamically allocating enough space and copying the contents of the original string. |

**Additional functions:**

|  **Function**   | **Description**                                                                                                                            |
| --------------- | ------------------------------------------------------------------------------------------------------------------------------------------ |
|   `ft_substr`   | Reserve (with malloc(3)) and return a substring of the string 's'. The substring starts from index 'start' and has a length of max. 'len'. |
|   `ft_strjoin`  | Reserve (with malloc(3)) and return a new string, formed by the concatenation of 's1' and 's2'.                                            |
|   `ft_strtrim`  | Removes all characters from the string 'set' from the beginning and end of 's1', until a character not belonging to 'set' is found. The resulting string is returned with a malloc(3) fallback. |
|   `ft_split`    | Reserve (using malloc(3)) an array of strings resulting from separating the string 's' into substrings using the character 'c' as a delimiter. The array must be terminated with a NULL pointer. |
|   `ft_itoa`     | Using malloc(3), generate a string that represents the integer value received as an argument. Negative numbers have to be managed.         |
|   `ft_strmapi`  | To each character of the string 's', apply the function 'f' giving as parameters the index of each character within 's' and the character itself. Generates a new string with the result of successive use of 'f' |
|  `ft_striteri`  | To each character of the string 's', apply the function 'f' giving as parameters the index of each character within 's' and the address of the character itself, which can be modified if necessary. |
| `ft_putchar_fd` | Sends the character 'c' to the specified file descriptor.                                                                                  |
| `ft_putstr_fd`  | Sends the string 's' to the specified file descriptor.                                                                                     |
| `ft_putendl_fd` | Sends the string 's' to the given file descriptor, followed by a line break.                                                               |
| `ft_putnbr_fd`  | Sends the number 'n' to the given file descriptor.                                                                                         |

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
| `ft_lstnew`       | Create a new node using malloc(3). The member variable 'content' is initialized with the content of the parameter 'content'. The 'next' variable, with NULL. |
| `ft_lstadd_front` | Add the 'new' node to the beginning of the 'lst' list.                                                                                                       |
| `ft_lstsize`      | Counts the number of nodes in a list.                                                                                                                        |
| `ft_lstlast`      | Returns the last node in the list.                                                                                                                           |
| `ft_lstadd_back`  | Add the 'new' node to the end of the 'lst' list.                                                                                                             |
| `ft_lstdelone`    | It takes as a parameter a node 'lst' and frees the memory of the content using the function 'del' given as a parameter, in addition to freeing the node. The 'next' memory must not be freed. |
| `ft_lstclear`     | Delete and free the given ’lst’ node and all consecutive nodes of that node, using the ’del’ and free(3) function. In the end, the pointer to the list must be NULL. |
| `ft_lstiter`      | Iterates the list 'lst' and applies the function 'f' on the content of each node.                                                                            |
| `ft_lstmap`       | Iterates the list 'lst' and applies the function 'f' to the contents of each node. Creates a list resulting from the correct and successive application of the function 'f' on each node. The 'del' function is used to delete the contents of a node, if necessary. |