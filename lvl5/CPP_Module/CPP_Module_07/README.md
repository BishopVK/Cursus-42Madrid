## Grade

| **Score** | **Description** |
|---|---|
| <p align="center"><img width="222px" alt="170px" src="./img/Score_100.png"></p> | **Full project** |

## CPP Module 07: C++ templates

This module introduces the concept of C++ templates for writing generic code. 

### Exercises

* **[Exercise 00: Start with a few functions](./ex00)**
    * This exercise involves implementing three function templates: `swap` (swaps the values of two given parameters, returning nothing), `min` (compares two values and returns the smallest one; if equal, returns the second), and `max` (compares two values and returns the greatest one; if equal, returns the second). These functions must be able to be called with any type of argument, provided the two arguments have the same type and support all necessary comparison operators. Templates must be defined in the header files.
* **[Exercise 01: Iter](./ex01)**
    * This exercise focuses on developing a function template `iter` that can apply another function to each element of an array of any type.
* **[Exercise 02: Array](./ex02)**
    * This exercise involves implementing a templated `Array` class that behaves like a dynamic array, supporting constructors (empty and with unsigned int parameter), copy operations (copy constructor and assignment operator with deep copy semantics), element access through the subscript operator (`[]`) with bounds checking (throwing `std::exception` if out of bounds), and a `size()` member function that returns the number of elements. Memory must be allocated using `new[]`.

### General Rules

* Code is compiled with `c++` and flags `-Wall -Wextra -Werror`.
* Code must compile with the `-std=c++98` flag.
* Class names are in UpperCamelCase.
* Output messages end with a newline character.
* The C++ standard library is allowed, but external libraries and certain C functions (`printf()`, `*alloc()`, `free()`) are forbidden.
* `using namespace <ns_name>` and `friend` keywords are forbidden unless explicitly stated.
* STL (containers, algorithms) is forbidden in this module.

---

| **⬅️ Previous exercise**              | **➡️ Next exercise**               |
| ------------------------------------ | --------------------------------- |
| [CPP_Module_06](../CPP_Module_06)    | [CPP_Module_08](../CPP_Module_08) |