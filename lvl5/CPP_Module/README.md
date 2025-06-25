
## CPP_Module

### Expanding C++ Skills: Advanced Features and STL Mastery

These next five modules delve deeper into C++, moving beyond core OOP principles to explore advanced language features and the powerful Standard Template Library (STL). This section covers how to gracefully handle runtime errors with exceptions, perform precise type conversions, write generic and reusable code using templates, and efficiently manage data with various STL containers, iterators, and algorithms. The focus is on creating robust, flexible, and high-performance C++ applications.

## Modules

The repository is organized into the following modules, each addressing specific aspects of C++:

* **[Module 05: Repetition and Exceptions](/lvl5/CPP_Module/CPP_Module_05)**
    * This module covers the management of errors and unexpected situations at runtime using C++ exception handling mechanisms. Practical experience is gained in designing classes that throw and catch exceptions, ensuring robust and fault-tolerant applications. This includes understanding custom exception types and implementing proper error propagation.

* **[Module 06: C++ casts](/lvl5/CPP_Module/CPP_Module_06)**
    * This module explores the various C++ casting operators (`static_cast`, `dynamic_cast`, `reinterpret_cast`, `const_cast`) and their appropriate use cases. It covers how to perform explicit type conversions safely and effectively, understanding their implications for polymorphism, and identifying scenarios where each cast is necessary or forbidden.

* **[Module 07: C++ templates](/lvl5/CPP_Module/CPP_Module_07)**
    * This module introduces C++ templates, enabling the writing of generic functions and classes that operate independently of the data type. It covers how to create function templates for common utilities (like `swap`, `min`, `max`) and design templated container classes, demonstrating the power of generic programming in C++.

* **[Module 08: Templated containers, iterators, algorithms](/lvl5/CPP_Module/CPP_Module_08)**
    * Building on templates, this module delves into the fundamental components of the Standard Template Library (STL): templated containers, iterators, and algorithms. It covers the use and interaction with various STL containers and the implementation of custom containers that expose iterator interfaces, preparing for efficient data manipulation.

* **[Module 09: STL](/lvl5/CPP_Module/CPP_Module_09)**
    * This module provides extensive hands-on experience with the Standard Template Library (STL). It involves applying knowledge of containers, iterators, and algorithms to solve complex problems, such as parsing data, evaluating expressions, and implementing sorting algorithms, with a focus on performance and efficient use of STL components.

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
* Follow the guidelines and avoid being lazy to maximize learning`