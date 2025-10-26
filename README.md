# C++ Module 00

This repository contains exercises from the C++ Module 00 curriculum at 42 Amman.

## Project Structure

```
cpp/
├── ex00/          # Megaphone exercise
│   ├── megaphone.cpp
│   └── Makefile
└── ex01/          # PhoneBook exercise
    ├── phonebook.cpp
    ├── phonebook.hpp
    ├── Contact.hpp
    ├── ContactOperations.cpp
    ├── ContactOperations.hpp
    └── Makefile
```

## Exercises

### Exercise 00: Megaphone

A simple program that converts command-line arguments to uppercase and outputs them.

**Features:**
- Converts all arguments to uppercase
- Trims whitespace from arguments
- Compresses multiple spaces into single spaces
- Outputs a default message if no arguments are provided

**Compilation:**
```bash
cd ex00
make
```

**Usage:**
```bash
./megaphone "shhhhh... I think the students are asleep..."
./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
./megaphone
```

---

### Exercise 01: PhoneBook

A simple phonebook application that stores and manages contact information.

**Features:**
- **ADD**: Add a new contact (stores up to 8 contacts, oldest gets replaced when full)
- **SEARCH**: Display all contacts in a formatted table and view details
- **EXIT**: Quit the program

**Contact Information:**
- First Name
- Last Name
- Nickname
- Phone Number
- Darkest Secret

**Compilation:**
```bash
cd ex01
make
```

**Usage:**
```bash
./phonebook
```

**Commands:**
- `ADD` - Add a new contact by entering the required information
- `SEARCH` - View all contacts and select one to see full details
- `EXIT` - Exit the program

---

## Compilation Standards

All exercises are compiled with:
- Compiler: `c++`
- Flags: `-Wall -Wextra -Werror -std=c++98`
- Standard: C++98

## Makefile Targets

Each exercise includes a Makefile with the following targets:
- `make` or `make all` - Compile the program
- `make clean` - Remove object files
- `make fclean` - Remove object files and executable
- `make re` - Recompile from scratch (ex01 only)

## Author

**halmuhis** - 42 Amman Student

## License

This project is part of the 42 Network curriculum.
