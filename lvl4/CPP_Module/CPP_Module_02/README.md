## Grade

| **Score**           | **Description**     |
|-----------------------|---------------|
| <p align="center"><img width="222px" alt="170px" src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl4/CPP_Module/CPP_Module_02/img/Score_100.png"></p> | **Mandatory part + Extra exercise** |


## CPP Module 02: Ad-hoc Polymorphism, Operator Overloading, and the Orthodox Canonical Class Form

This module explores ad-hoc polymorphism, operator overloading, and the Orthodox Canonical Class Form.

### New Rules

* From this module onwards, all classes must adhere to the Orthodox Canonical Form, which includes:
    * Default constructor
    * Copy constructor
    * Copy assignment operator
    * Destructor
* Class code should be split into header files (.hpp/.h) for definitions and source files (.cpp) for implementation.

### Exercises

* **[Exercise 00: My First Class in Orthodox Canonical Form](/lvl4/CPP_Module/CPP_Module_02/ex00)**

    * This exercise involves creating a simple class (likely `Fixed`) that adheres to the Orthodox Canonical Form.
* **[Exercise 01: Towards a more useful fixed-point number class](/lvl4/CPP_Module/CPP_Module_02/ex01)**

    * This exercise builds upon the previous one, adding functionality to the `Fixed` class, such as converting to floating-point or integer types and output stream insertion.
* **[Exercise 02: Now we're talking](/lvl4/CPP_Module/CPP_Module_02/ex02)**

    * This exercise focuses on operator overloading for the `Fixed` class, including comparison and arithmetic operators. It also introduces min/max static member functions.
* **[Extra: Exercise 03: BSP](/lvl4/CPP_Module/CPP_Module_02/ex03)**

    * This exercise likely involves using the `Fixed` class and potentially a `Point` class to implement a Binary Space Partitioning (BSP) algorithm or a related geometric calculation.

### General Rules

* Code is compiled with `c++` and flags `-Wall -Wextra -Werror`.
* Code must compile with the `-std=c++98` flag.
* Class names are in UpperCamelCase.
* Output messages end with a newline character.
* The C++ standard library is allowed, but external libraries and certain C functions are forbidden.