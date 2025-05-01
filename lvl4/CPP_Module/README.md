## CPP_Module

This repository contains my solutions to the C++ modules. These modules cover fundamental to advanced C++ concepts, focusing on Object-Oriented Programming (OOP) and C++98 standards[cite: 226, 227, 228, 229, 230, 231, 348, 349, 350, 351, 352, 494, 495, 496, 497, 498, 499, 592, 593, 594, 595, 596, 787, 788, 789, 790, 791, 792, 911, 912, 913, 914, 915, 1130, 1131, 1132, 1133, 1134, 1135, 1256, 1257, 1258, 1259, 1412, 1413, 1414, 1415, 1416, 1417].

## Modules

The repository is organized into the following modules, each addressing specific aspects of C++:

* **Module 00:  Basic C++ Concepts**
    * Introduces namespaces, classes, member functions, I/O streams, initialization lists, `static`, `const`, and other basic C++ features[cite: 1407].
    * Key exercises include creating a megaphone program and a simple phonebook application[cite: 1409].

* **Module 01: Memory Management and References**
    * Covers memory allocation, pointers to members, references, and switch statements[cite: 1125].
    * Exercises involve working with dynamic memory, references, and implementing a Harl filter[cite: 1127].

* **Module 02: Ad-hoc Polymorphism and Operator Overloading**
    * Explores ad-hoc polymorphism, operator overloading, and the Orthodox Canonical Class Form[cite: 782].
    * Focuses on creating classes with overloaded operators and implementing a function to determine if a point is within a triangle[cite: 784].

* **Module 03: Inheritance**
    * Introduces inheritance in C++[cite: 490].
    * Exercises involve creating class hierarchies and demonstrating proper construction and destruction chaining[cite: 491].

* **Module 04:  Polymorphism, Abstract Classes, and Interfaces**
    * Covers subtype polymorphism, abstract classes, and interfaces[cite: 221].
    * Focuses on implementing abstract classes and interfaces to achieve polymorphic behavior[cite: 223].

## General Rules

* **Compilation:** Code is compiled using `c++` with the flags `-Wall -Wextra -Werror` and should compile with the `-std=c++98` flag[cite: 233, 332, 501, 677, 794, 941, 1137, 1281, 1419].
* **Naming Conventions:** Exercise directories are named `ex00`, `ex01`, etc. Class names are in UpperCamelCase, and files are named accordingly (e.g., `ClassName.hpp`, `ClassName.cpp`)[cite: 233, 234, 235, 333, 334, 335, 501, 502, 503, 678, 679, 680, 795, 796, 942, 943, 944, 1138, 1139, 1282, 1283, 1284, 1420, 1421].
* **Output:** Unless specified otherwise, output messages end with a newline character and are displayed to standard output[cite: 236, 504, 797, 1140].
* **Coding Style:** No specific coding style is enforced, but code should be clean and readable[cite: 237, 238, 336, 337, 798, 799, 1141, 1142].
* **Allowed/Forbidden:** The C++ standard library is allowed, but external libraries (C++11, Boost) and certain C functions (`printf()`, `*alloc()`, `free()`) are forbidden[cite: 239, 240, 241, 242, 243, 338, 339, 340, 386, 387, 388, 505, 506, 507, 630, 631, 632, 800, 801, 802, 803, 804, 945, 946, 947, 948, 1143, 1144, 1145, 1146, 1288, 1289, 1290, 1291, 1292].  `using namespace <ns_name>` and `friend` keywords are also generally forbidden[cite: 63, 389, 806, 950].
* **STL Usage:** The Standard Template Library (STL) is allowed only in Modules 08 and 09[cite: 64, 390, 807, 951].

##  Important Notes

* Each exercise requires comprehensive testing[cite: 95].
* Constructors and destructors should display specific messages[cite: 96, 122].
* Follow the guidelines and avoid being lazy to maximize learning[cite: 92, 93, 94, 323, 324, 325, 422, 423, 424, 665, 666, 667, 987, 988, 989, 1323, 1324, 1325].