## Exercise: max

The **max** exercise requires implementing a function in C that returns the largest number from an array of integers.

This task strengthens your understanding of basic array manipulation and control structures in C.

## Function Prototype

```c
int	max(int* tab, unsigned int len);
```

## Requirements

- The function takes:
  - `tab`: a pointer to the first element of an array of integers.
  - `len`: the number of elements in the array.
- It must return the maximum integer found in the array.
- If the array is empty (`len == 0`), the function should return `0`.

## Key Points

- You must manually iterate through the array to find the largest number.
- No standard library functions are allowed.
- The function should return immediately with `0` if `len == 0`.

## Example Usage

```c
#include <stdio.h>

int	main(void)
{
	int	arr[] = {3, 7, 2, 9, 5};
	printf("Max: %d\n", max(arr, 5));
	return (0);
}
```

### Output:

```
Max: 9
```

## What This Exercise Does Not Handle

- Sorting the array.
- Handling `NULL` pointers.
- Floating-point or non-integer values.

## My solution

| **#** | **File**                          |
| ----- | --------------------------------- |
|  `1`  | [**max.c**](max.c)          |