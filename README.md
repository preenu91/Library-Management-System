# Library Management System in C++

A simple console-based **Library Management System** implemented in C++ to manage books in a library. The system allows users to add, remove, and search for books and borrow and return books, with input validation and error handling.

## Features 
-**Add Books**: Add a new book to the library with details like title, author, and ISBN.
- **Remove Books**: Remove a book from the library by its ISBN.
- **Search Books**: Search for books by title or ISBN.
- **Borrow & Return Books**: Track the availability of books, allowing users to borrow and return books.
- **Input Validation**: Ensures the library doesn't exceed its maximum capacity (100 books) and validates user inputs.

## Class Structure

### `Book` Class

The `Book` class has the following member functions and variables:

- **Private Member Variables**:
  - `title` (string)
  - `author` (string)
  - `isbn` (string)
  - `available` (boolean)

- **Public Member Functions**:
  - `setTitle(string title)`
  - `setAuthor(string author)`
  - `setISBN(string isbn)`
  - `setAvailable(bool available)`
  - `getTitle()`
  - `getAuthor()`
  - `getISBN()`
  - `getAvailable()`
  - `borrowBook()`
  - `returnBook()`

### Library Management

The system uses a **dynamic array** to hold a maximum of **100 books** and prompts the user to interact with the library (add, remove, or search for books).

## How to Run

1. Clone or download this repository to your local machine.
2. Open a terminal or command prompt.
3. Navigate to the project folder.
4. Compile the code with a C++ compiler (e.g., g++).
   ```bash
   g++ -o library_management main.cpp
5. Run
 ```bash
    ./library_management

## Example Usage
Welcome to the Library Management System!
Please choose an option:
1. Add a book
2. Remove a book
3. Search for a book
4. Borrow a book
5. Return a book
6. Exit

Option 1:
Enter book title: "The Great Gatsby"
Enter author: "F. Scott Fitzgerald"
Enter ISBN: "9780743273565"

Book added successfully!

Option 3:
Enter book title or ISBN to search: "The Great Gatsby"
Book found: The Great Gatsby by F. Scott Fitzgerald

## License

## Contributions
Feel free to fork the repository and submit pull requests for improvements or bug fixes.
