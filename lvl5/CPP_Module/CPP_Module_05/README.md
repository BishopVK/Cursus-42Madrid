## Grade

| **Score** | **Description** |
|---|---|
| <p align="center"><img width="222px" alt="170px" src="./img/Score_100.png"></p> | **Full project** |

## CPP Module 05: Repetition and Exceptions

[cite_start]This module focuses on handling repetition and exceptions in C++. 

### Exercises

* **[Exercise 00: Mommy, when I grow up, I want to be a bureaucrat!](/lvl4/CPP_Module/CPP_Module_05/ex00)**
    * This exercise involves designing a `Bureaucrat` class. It has a constant name and a grade (1 to 150). [cite_start]Attempts to instantiate a `Bureaucrat` with an invalid grade must throw `Bureaucrat::GradeTooHighException` or `Bureaucrat::GradeTooLowException`. [cite_start]Getters for name and grade are required, along with member functions to increment or decrement the grade, which also throw exceptions if the grade goes out of range. [cite_start]An overload of the insertion (`<<`) operator is to be implemented for printing bureaucrat information.
* **[Exercise 01: Form up, maggots!](/lvl4/CPP_Module/CPP_Module_05/ex01)**
    * [cite_start]This project involves creating a `Form` class with a constant name, a boolean indicating if it is signed (initially false), and constant grades required to sign and execute it. [cite_start]Grade rules are similar to `Bureaucrat`, throwing `Form::GradeTooHighException` or `Form::GradeTooLowException` for invalid grades. [cite_start]Getters for all attributes and an overloaded `<<` operator are required. [cite_start]A `beSigned()` member function takes a `Bureaucrat` and attempts to sign the form if the bureaucrat's grade is sufficient, throwing `Form::GradeTooLowException` if not. [cite_start]The `signForm()` member function in the `Bureaucrat` class is modified to call `Form::beSigned()` and print appropriate success or failure messages.
* **[Exercise 02: No, you need form 28B, not 28C...](/lvl4/CPP_Module/CPP_Module_05/ex02)**
    * This exercise involves developing concrete form classes (e.g., `ShrubberyCreationForm`, `RobotomyRequestForm`, `PresidentialPardonForm`) that inherit from an abstract `AForm` class, demonstrating polymorphism.
* **[Exercise 03: At least this beats coffee-making](/lvl4/CPP_Module/CPP_Module_05/ex03)**
    * This exercise likely involves further development of the form and bureaucrat system, building upon the concepts of repetition and exceptions.

### General Rules

* [cite_start]Code is compiled with `c++` and flags `-Wall -Wextra -Werror`.
* [cite_start]Code must compile with the `-std=c++98` flag.
* [cite_start]Class names are in UpperCamelCase.
* [cite_start]Output messages end with a newline character.
* [cite_start]The C++ standard library is allowed, but external libraries and certain C functions (`printf()`, `*alloc()`, `free()`) are forbidden.
* [cite_start]`using namespace <ns_name>` and `friend` keywords are forbidden unless explicitly stated.
* [cite_start]STL (containers, algorithms) is forbidden in this module.