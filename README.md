# Phone Book CLI Application (C++)

This is a command-line based **Phone Book Application** developed using **C++**. It demonstrates key programming concepts such as **Object-Oriented Programming**, **File I/O**, and use of **STL containers** (`vector`, `fstream`).

The application allows users to add, view, search, update, and delete contacts, with persistent storage support.

---

## Features

- Add new contacts (Name and Phone Number)
- View all saved contacts
- Search by name or number
- Update existing contact information
- Delete a contact by name
- Delete all contacts at once
- View total number of saved contacts
- Data saved to `contacts.txt` for persistence

---

## Technologies Used

- **C++**
- **Standard Template Library (STL)** — `vector`, `fstream`, `string`
- File handling for persistent storage
- Modular OOP design

---

## Getting Started

### Requirements

- C++ compiler (GCC, Clang, or MSVC)
- Terminal or Command Prompt

### How to Run

1. **Clone the repository**
    ```bash
    git clone https://github.com/Vilsium/Phonebook.git
    cd Phonebook

2. **Compiler the code**
    ```bash
    g++ phonebook.cpp -o phonebook

3. **Run the executable**
    ```bash
    ./phonebook

### Sample Menu Output

========= PHONE BOOK MENU =========
1. Add Contact
2. Display All Contacts
3. Search by Name
4. Search by Number
5. Update Contact
6. Delete Contact
7. Delete All Contacts
8. Count Contacts
9. Exit

### File Structure

📁 phonebook-cli-cpp
├── 📄 main.cpp         # Main source code (C++)
├── 📄 contacts.txt     # File that stores contact data (auto-generated)
└── 📄 README.md        # Project documentation
