## Grade

| **Score** | **Description** |
|---|---|
| <p align="center"><img width="222px" alt="170px" src="./img/Score_100.png"></p> | **Full project** |

## CPP Module 06: C++ casts

This module covers different types of C++ casts, allowing explicit type conversions. 

### Exercises

* **[Exercise 00: Conversion of scalar types](./ex00)**
    * This exercise requires creating a `ScalarConverter` class that contains only one static method named `convert`. This method takes a string representation of a C++ literal and outputs its value in `char`, `int`, `float`, and `double` types. It must handle pseudo-literals like `-inff`, `+inff`, `nanf`, `inf`, `+inf`, and `nan`. Informative messages should be printed if a conversion to `char` is not displayable. The class must not be instantiable.
* **[Exercise 01: Serialization](./ex01)**
    * This exercise involves implementing functions to serialize and deserialize a `Data` structure to and from an unsigned integer type using `reinterpret_cast`.
* **[Exercise 02: Identify real type](./ex02)**
    * This exercise focuses on creating a `Base` class with a public virtual destructor and three empty classes (`A`, `B`, `C`) that publicly inherit from `Base`. It requires implementing `generate` (randomly instantiates A, B, or C and returns as a `Base` pointer) and `identify` functions (one taking a `Base*` and one taking a `Base&`) to dynamically print the actual type of the object ("A", "B", or "C") using `dynamic_cast`.

### General Rules

* Code is compiled with `c++` and flags `-Wall -Wextra -Werror`.
* Code must compile with the `-std=c++98` flag.
* Class names are in UpperCamelCase.
* Output messages end with a newline character.
* The C++ standard library is allowed, but external libraries and certain C functions (`printf()`, `*alloc()`, `free()`) are forbidden.
* `using namespace <ns_name>` and `friend` keywords are forbidden unless explicitly stated.
* STL (containers, algorithms) is forbidden in this module.
* Type conversion must be handled using a specific type of casting for each exercise.