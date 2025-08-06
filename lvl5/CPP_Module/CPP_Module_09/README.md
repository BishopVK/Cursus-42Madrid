## Grade

| **Score** | **Description** |
|---|---|
| <p align="center"><img width="222px" alt="170px" src="./img/Score_100.png"></p> | **Full project** |

## CPP Module 09: STL

This module extensively uses the Standard Template Library (STL) and mandates the use of standard containers. 

### Exercises

* **[Exercise 00: Bitcoin Exchange](./ex00)**
    * This exercise requires creating a program named `btc` that outputs the value of a certain amount of Bitcoin on a given date. The program must use a provided CSV database of Bitcoin prices over time. It takes a file as an argument, with each line in the format "date | value". Valid dates are Year-Month-Day, and valid values are positive floats or integers between 0 and 1000. If a date in the input does not exist in the database, the closest lower date's exchange rate must be used. Error handling with appropriate messages is required for invalid inputs. At least one standard container must be used.
* **[Exercise 01: Reverse Polish Notation](./ex01)**
    * This exercise involves creating a program named `RPN` that takes an inverted Polish mathematical expression as an argument. The program must process this expression and output the correct result. Numbers used in the operation will always be less than 10. The program must be able to handle operations with `+`, `-`, `/`, `*` tokens, and display an error message on standard error if an error occurs.
* **[Exercise 02: PmergeMe](./ex02)**
    * This exercise focuses on implementing the Ford-Johnson algorithm (Merge-Insert Sort) to sort a sequence of positive integers efficiently. It requires using two different standard containers (e.g., `std::vector` and `std::list` are suggested) and measuring the time taken for sorting with each.

### General Rules

* Code is compiled with `c++` and flags `-Wall -Wextra -Werror`.
* Code must compile with the `-std=c++98` flag.
* Class names are in UpperCamelCase.
* Output messages end with a newline character.
* The C++ standard library is allowed, but external libraries and certain C functions (`printf()`, `*alloc()`, `free()`) are forbidden.
* `using namespace <ns_name>` and `friend` keywords are forbidden unless explicitly stated.
* STL (containers, algorithms) is allowed in this module and Module 08.
* It is mandatory to use standard containers for each exercise in this module, and once a container is used, it cannot be used for the rest of the module. At least one container must be used per exercise, except for exercise 02 which requires two.

---

| **⬅️ Previous exercise**           |
| --------------------------------- |
| [CPP_Module_08](../CPP_Module_08) |