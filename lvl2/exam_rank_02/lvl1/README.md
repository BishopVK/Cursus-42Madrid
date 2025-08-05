## Exercise: ft_putstr

The **ft_putstr** exercise requires implementing a simple function in C that prints a string to the standard output using only the `write` system call.

This is one of the foundational exercises in learning how to interact with low-level I/O in C, and helps reinforce concepts like pointer manipulation and character iteration.

## Function Prototype

```c
void	ft_putstr(char *str);
```

## Requirements

- The function takes a single argument: a pointer to a null-terminated string.
- It must print the string to `stdout` (file descriptor 1).
- You must **only** use the `write()` function.  
  No `printf`, `puts`, `putchar`, or any standard library functions are allowed.

## Key Points

- You should iterate through the string using a pointer or index.
- Make sure not to write characters after the null terminator.
- The function must **not** return anything.

## Example Usage

```c
int main(void)
{
	ft_putstr("Hello, world!\n");
	return (0);
}
```

### Output:

```
Hello, world!
```

## What This Exercise Does Not Handle

- `NULL` pointer checks or error handling.
- Unicode or wide characters.
- Printing individual characters or numbers.

## My solution

| **#** | **File**                              |
| ----- | ------------------------------------- |
|  `1`  | [**ft_putstr.c**](ft_putstr.c)  |