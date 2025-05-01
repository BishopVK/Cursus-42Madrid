## CPP_Module

This repository contains my solutions to the C++ modules. These modules cover fundamental to advanced C++ concepts, focusing on Object-Oriented Programming (OOP) and C++98 standards.

## Modules

The repository is organized into the following modules, each addressing specific aspects of C++:

* **Module 00: Basic C++ Concepts**
    * Introduces namespaces, classes, member functions, I/O streams, initialization lists, `static`, `const`, and other basic C++ features.
    * Key exercises include creating a megaphone program and a simple phonebook application.

* **Module 01: Memory Management and References**
    * Covers memory allocation, pointers to members, references, and switch statements.
    * Exercises involve working with dynamic memory, references, and implementing a Harl filter.

* **Module 02: Ad-hoc Polymorphism and Operator Overloading**
    * Explores ad-hoc polymorphism, operator overloading, and the Orthodox Canonical Class Form.
    * Focuses on creating classes with overloaded operators and implementing a function to determine if a point is within a triangle.

* **Module 03: Inheritance**
    * Introduces inheritance in C++.
    * Exercises involve creating class hierarchies and demonstrating proper construction and destruction chaining.

* **Module 04: Polymorphism, Abstract Classes, and Interfaces**
    * Covers subtype polymorphism, abstract classes, and interfaces.
    * Focuses on implementing abstract classes and interfaces to achieve polymorphic behavior.

## General Rules

* **Compilation:** Code is compiled using `c++` with the flags `-Wall -Wextra -Werror` and should compile with the `-std=c++98` flag.
* **Naming Conventions:** Exercise directories are named `ex00`, `ex01`, etc. Class names are in UpperCamelCase, and files are named accordingly (e.g., `ClassName.hpp`, `ClassName.cpp`).
* **Output:** Unless specified otherwise, output messages end with a newline character and are displayed to standard output.
* **Coding Style:** No specific coding style is enforced, but code should be clean and readable.
* **Allowed/Forbidden:** The C++ standard library is allowed, but external libraries (C++11, Boost) and certain C functions (`printf()`, `*alloc()`, `free()`) are forbidden. `using namespace <ns_name>` and `friend` keywords are also generally forbidden.
* **STL Usage:** The Standard Template Library (STL) is allowed only in Modules 08 and 09.

## Important Notes

* Each exercise requires comprehensive testing.
* Constructors and destructors should display specific messages.
* Follow the guidelines and avoid being lazy to maximize learning.