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

**Flow & Structure**
- `main` is the only entry point. It checks `argc` and prints the fallback message (`* LOUD... *`) when no arguments are provided.
- When arguments exist, `main` loops from `argv[1]` to `argv[argc - 1]` and pipes each through two helpers before writing to `std::cout`.
- `trim` strips leading/trailing whitespace by walking the string from both ends.
- `compressSpaces` collapses repeated whitespace segments inside the argument to a single space so the output line feels "clean".
- After processing each argument the code inserts one extra space between arguments and ends the program with a newline.

**Features:**
- Converts all arguments to uppercase (include `<cctype>` to leverage `std::toupper` if desired)
- Trims whitespace from arguments (`trim`)
- Compresses multiple spaces into single spaces (`compressSpaces`)
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

**Flow & Structure**
- `main` instantiates a `PhoneBook` then hands control to `commandLoop`.
- `commandLoop` continuously reads a command line and dispatches it to `addContact`, `searchContact`, or exits on `EXIT`/EOF.
- `Contact` encapsulates the five text fields (first, last, nickname, phone number, darkest secret) with simple setters/getters.
- `PhoneBook` owns a circular array of 8 `Contact` objects plus two integers (`contactCount`, `nextIndex`). `addContact` overwrites the oldest entry when the storage is full.
- `addContact(PhoneBook&)` interacts with the user, validates that every field is non-empty, populates a temporary `Contact`, and pushes it into the phone book.
- `searchContact(PhoneBook&)` prints a formatted table (`std::setw` + truncation with a trailing dot) via `PhoneBook::displayContacts`. When the user enters a valid index, it prints the selected contact in detail.
- `displayContacts` guards against empty books, prints a consistent header, then enumerates the stored contacts in insertion order, truncating per the subject (10 chars + `.` when longer).

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
