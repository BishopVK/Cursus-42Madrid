## Grade

| **Score** | **Description** |
|---|---|
| <p align="center"><img width="222px" alt="170px" src="./img/Score_100.png"></p> | **Full project** |

## CPP Module 05: Repetition and Exceptions

This module focuses on handling repetition and exceptions in C++. 

### Exercises

* **[Exercise 00: Mommy, when I grow up, I want to be a bureaucrat!](./ex00)**
    * This exercise involves designing a `Bureaucrat` class. It has a constant name and a grade (1 to 150). Attempts to instantiate a `Bureaucrat` with an invalid grade must throw `Bureaucrat::GradeTooHighException` or `Bureaucrat::GradeTooLowException`. Getters for name and grade are required, along with member functions to increment or decrement the grade, which also throw exceptions if the grade goes out of range. An overload of the insertion (`<<`) operator is to be implemented for printing bureaucrat information.
* **[Exercise 01: Form up, maggots!](./ex01)**
    * This project involves creating a `Form` class with a constant name, a boolean indicating if it is signed (initially false), and constant grades required to sign and execute it. Grade rules are similar to `Bureaucrat`, throwing `Form::GradeTooHighException` or `Form::GradeTooLowException` for invalid grades. Getters for all attributes and an overloaded `<<` operator are required. A `beSigned()` member function takes a `Bureaucrat` and attempts to sign the form if the bureaucrat's grade is sufficient, throwing `Form::GradeTooLowException` if not. The `signForm()` member function in the `Bureaucrat` class is modified to call `Form::beSigned()` and print appropriate success or failure messages.
* **[Exercise 02: No, you need form 28B, not 28C...](./ex02)**
    * This exercise involves developing concrete form classes (e.g., `ShrubberyCreationForm`, `RobotomyRequestForm`, `PresidentialPardonForm`) that inherit from an abstract `AForm` class, demonstrating polymorphism.
* **[Exercise 03: At least this beats coffee-making](./ex03)**
    * This exercise likely involves further development of the form and bureaucrat system, building upon the concepts of repetition and exceptions.

### General Rules

* Code is compiled with `c++` and flags `-Wall -Wextra -Werror`.
* Code must compile with the `-std=c++98` flag.
* Class names are in UpperCamelCase.
* Output messages end with a newline character.
* The C++ standard library is allowed, but external libraries and certain C functions (`printf()`, `*alloc()`, `free()`) are forbidden.
* `using namespace <ns_name>` and `friend` keywords are forbidden unless explicitly stated.
* STL (containers, algorithms) is forbidden in this module.

---

| **➡️ Next exercise**               |
| --------------------------------- |
| [CPP_Module_06](../CPP_Module_06) |