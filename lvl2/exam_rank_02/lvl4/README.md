## Exercise: fprime

The **fprime** exercise is a command-line program that prints the prime factorization of a given positive integer in ascending order.

This task reinforces your understanding of control flow, loops, and basic arithmetic logic in C, especially in the context of number theory.

## Allowed Functions

- `printf`
- `atoi`

## Program Behavior

- The program takes **one** command-line argument: a positive integer.
- It prints the **prime factors** of the number, in ascending order, separated by `*`.
- The output must be followed by a newline.
- If the number of arguments is not exactly 1, it must print only a newline.

## Examples

```bash
$> ./fprime 225225 | cat -e
3*3*5*5*7*11*13$

$> ./fprime 8333325 | cat -e
3*3*5*5*7*11*13*37$

$> ./fprime 9539 | cat -e
9539$

$> ./fprime 804577 | cat -e
804577$

$> ./fprime 42 | cat -e
2*3*7$

$> ./fprime 1 | cat -e
1$

$> ./fprime | cat -e
$

$> ./fprime 42 21 | cat -e
$
```

## Key Points

- The number **1** is a special case and must print **1**.
- Input is guaranteed to be valid, so no need for input validation.
- Your algorithm must be efficient enough to handle large prime inputs.

## What This Exercise Does Not Handle

- Negative numbers or zero (input is always positive and valid).
- Memory allocation or pointer manipulation.
- Input validation or error messages.

## My solution

| **#** | **File**                              |
| ----- | ------------------------------------- |
|  `1`  | [**fprime.c**](fprime.c)              |

---

| **⬅️ Previous exercise** |
| ----------------------- |
| [ft_range](../lvl3)     |