# C++ Module 00

## Overview
This project marks the beginning of the C++ curriculum, serving as the fundamental transition from procedural C programming to **Object-Oriented Programming (OOP)**.

The module focuses on adapting to the specific syntax and philosophy of the C++ language while adhering strictly to the **C++98 standard**.

## Educational Goals
The primary objective is to build a strong foundation in C++ mechanics before advancing to complex containers and algorithms. Key concepts covered include:

* **Object-Oriented Paradigm**: Designing software using **classes** and **member functions** rather than standalone functions.
* **Encapsulation**: Structuring code and visibility using **namespaces**.
* **Standard I/O**: Managing input and output via **stdio streams** (`std::cin`, `std::cout`) instead of C-style functions.
* **Memory & Initialization**: Correctly using **initialization lists** and understanding keywords like `static` and `const` in a C++ context.

## Technical Requirements
This project is built according to strict C++98 standards.

* **Language Standard**: C++98
* **Compiler**: `c++`
* **Compilation Flags**: `-Wall -Wextra -Werror`
* **Forbidden**: Standard C functions (`printf`, `alloc`, `free`) and external libraries (Boost, C++11 features).

## Build Instructions
The project is divided into multiple exercises, each containing a dedicated `Makefile`. To compile a specific exercise:

1.  Navigate to the exercise directory:
    ```bash
    cd ex01
    ```
2.  Compile the source code:
    ```bash
    make
    ```
3.  Run the executable:
    ```bash
    ./phonebook
    ```

---
*This project is part of the 42 Network Curriculum.*