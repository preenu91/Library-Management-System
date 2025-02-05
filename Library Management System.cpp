// Library Management System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

// Class representing a book in the library
class Book
{
private:
    std::string title;
    std::string author;
    std::string isbn;
    bool available;

public:
    // Flag to track if the book has been initialized
    bool isInitialized = false;
    // Destructor to indicate when a book object is destroyed
    ~Book()
    {
        if (isInitialized)
        {
            std::cout << "Book object with title " << this->title << " has been destroyed\n";

        }
    }

    // Setters for book details
    void setTitle(std::string t)
    {
        title = t;
        isInitialized = true;
    }
    void setAuthor(std::string a)
    {
        author = a;
    }
    void setISBN(std::string i)
    {
        isbn = i;
    }
    void setAvailable(bool a)
    {
        available = a;
    }

    // Getters for book details
    std::string getTitle()
    {
        return  title;
    }
    std::string getAuthor()
    {
        return  author;
    }
    std::string getISBN()
    {
        return  isbn;
    }
    std::string getAvailable()
    {
        return available ? "Book available" : "Checked Out";

    }

    // Function to borrow a book
    void borrowBook()
    {
        if (available)
        {
            available = false;
            std::cout << "Book borrowed suucessfully!\n";
        }
        else
            std::cout << "Book is not available\n";
    }


    // Function to return a book
    void returnBook()
    {
        if (!available)
        {
            available = true;
            std::cout << "Book returned successfully!\n";
        }
        else
            std::cout << "Book is already available\n";
    }

    
};

int main()
{
    Book* books = new Book[100];
    int choice{}, numBooks{};
    std::string title, isbn, author;
    bool found;
        
    do
    {
        // Display menu options
        std::cout << "Welcome to the library management system!"<<std::endl;
        std::cout << "Menu" << std::endl;
        std::cout << "1. Add book" << std::endl;
        std::cout << "2. Remove book" << std::endl;
        std::cout << "3. Search for book" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice" << std::endl;
        std::cin >> choice;
        std::cin.ignore();

        // Perform actions based on user choice
        switch (choice)
        {
        case 1: //add a book to the library
            if (numBooks < 100)
            {
                std::cout << "Enter book title: ";
                std::getline(std::cin, title);
                //std::cin.ignore();
                books[numBooks].setTitle(title);

                std::cout << "Enter book author:";
                std::getline(std::cin, author);
                //std::cin.ignore();
                books[numBooks].setAuthor(author);

                std::cout << "Enter book ISBN: ";
                std::getline(std::cin, isbn);
                //std::cin.ignore();
                books[numBooks].setISBN(isbn);

                books[numBooks].setAvailable(true);
                numBooks++;
                std::cout << "Book added to library.\n";
                //std::cin.ignore();
            }
            else
            {
                std::cout << "Maximum capacity of books exceeded\n";
            }
            break;

        case 2: // remove a book from the library
            std::cout << "Enter ISBN:";
            std::getline(std::cin, isbn);
            found = false;
            for (int i = 0; i < numBooks; i++)
            {
                if (books[i].getISBN() == isbn)
                {
                    books[i].setAvailable(false);
                    std::cout << "Book removed from library.\n";
                    found = true;
                }
            }
            if (!found)
            {
                std::cout << "Book with this ISBN not found.\n";
            }

            break;
        case 3: //  search for a book in the library using isbn
            std::cout << "Enter ISBN: ";
            std::getline(std::cin, isbn);
            found = false;
            for (int i = 0; i < numBooks; i++)
            {
                if (books[i].getISBN() == isbn)
                {
                    std::cout << "Title: ";
                    std::cout << books[i].getTitle() << std::endl;
                    std::cout << "Author: ";
                    std::cout << books[i].getAuthor() << std::endl;
                    std::cout << "ISBN: ";
                    std::cout << books[i].getISBN() << std::endl;
                    std::cout << "Availability: ";
                    std::cout << books[i].getAvailable() << std::endl;
                    found = true;
                }
            }
            if (!found)
            {
                std::cout << "No book found with the provided ISBN.\n";
            }
                
            break;

        case 4:
            std::cout << "Thank you for using the library management system!\n";
            break;
        default:
            std::cout << "Invalid choice! Try again\n";
            break;


        }
    } while (choice != 4);
    

    delete[] books;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
