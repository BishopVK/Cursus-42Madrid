## Exercise: ft_range

The **ft_range** exercise requires implementing a function in C that returns an array of consecutive integers from `start` to `end`, inclusive.

This exercise helps practice dynamic memory allocation with `malloc()` and manipulating integer ranges in C.

## Function Prototype

```c
int	*ft_range(int start, int end);
```

## Requirements

- The function takes two integers: `start` and `end`.
- It allocates an array using `malloc()` and fills it with all the values from `start` to `end` (inclusive).
- It must return a pointer to the beginning of the array.
- The array should work whether `start` is less than, equal to, or greater than `end`.

## Key Points

- Make sure to compute the number of elements correctly, accounting for both increasing and decreasing ranges.
- You must handle cases like:
  - `start < end`
  - `start > end`
  - `start == end`
- No memory leaks allowed — every element must be initialized.

## Example Usages

```c
ft_range(1, 3);     // returns [1, 2, 3]
ft_range(-1, 2);    // returns [-1, 0, 1, 2]
ft_range(0, 0);     // returns [0]
ft_range(0, -3);    // returns [0, -1, -2, -3]
```

## What This Exercise Does Not Handle

- Input validation.
- Freeing the allocated memory (handled by the caller).
- Null checks for invalid allocation (optional but recommended).

## My solution

| **#** | **File**                              |
| ----- | ------------------------------------- |
|  `1`  | [**ft_range.c**](ft_range.c)    |