/*
## Creating a Library Management System
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * @struct DATE
 * @brief Represents a date with day, month, and year.
 * 
 * This struct is used to store and manipulate dates in the library management system.
 * It contains three integer fields: date, month, and year.
 */
struct DATE {
    int date;
    int month;
    int year;
};

/**
 * @struct Book
 * @brief Represents a book in the library management system.
 * 
 * This struct stores information about a book, including its name, author, and publish date.
 */
struct Book {
    string name;
    string author;
    DATE publish_date;
};

/**
 * Displays the inventory of books.
 * 
 * @param books A vector of Book pointers representing the inventory of books.
 */
void showInventory(const vector<Book*>& books) {
    if (books.empty()) {
        cout << "The inventory is empty." << endl;
        return;
    }

    cout << "Showing all books in inventory:" << endl;
    for (const auto& book : books) {
        cout << "Name: " << book->name << ", Author: " << book->author
             << ", Publish Date: " << book->publish_date.date << "/"
             << book->publish_date.month << "/" << book->publish_date.year << endl;
    }
}

/**
 * Displays information about a book based on its name.
 * 
 * @param books A vector of pointers to Book objects.
 */
void showBook(const vector<Book*>& books) {
    string bookName;
    cout << "Enter the name of the book: ";
    cin.ignore();
    getline(cin, bookName);

    for (const auto& book : books) {
        if (book->name == bookName) {
            cout << "Name: " << book->name << ", Author: " << book->author
                 << ", Publish Date: " << book->publish_date.date << "/"
                 << book->publish_date.month << "/" << book->publish_date.year << endl;
            return;
        }
    }
    cout << "Book not found!" << endl;
}

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

/**
 * Checks if a given date is valid.
 *
 * @param day The day of the date.
 * @param month The month of the date.
 * @param year The year of the date.
 * @return True if the date is valid, false otherwise.
 */
bool isValidDate(int day, int month, int year) {

    if (year < 1 || month < 1 || month > 12 || day < 1) {
        return false;
    }

    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (month == 2 && isLeapYear(year)) {
        daysInMonth[1] = 29;
    }

    return day <= daysInMonth[month - 1];
}

/**
 * Adds a new book to the library.
 * 
 * @param books A vector of Book pointers representing the library's collection of books.
 */
void addBook(vector<Book*>& books) {
    Book* newBook = new Book;
    cout << "Enter book name: ";
    cin.ignore();
    getline(cin, newBook->name);
    cout << "Enter author name: ";
    getline(cin, newBook->author);

    cout << "Enter publish date (DD MM YYYY): ";
    valid_date:
    cin >> newBook->publish_date.date >> newBook->publish_date.month >> newBook->publish_date.year;
    if (isValidDate(newBook->publish_date.date, newBook->publish_date.month, newBook->publish_date.year)) {
        books.push_back(newBook);
        cout << "Book added successfully!" << endl;
    } else {
        cout << "enter a valid date (DD MM YYYY): ";
        goto valid_date;
    }
    return;
}

/**
 * @brief Allows the user to edit the details of a book in the library management system.
 * 
 * @param books A vector of pointers to Book objects representing the collection of books.
 * 
 * The function prompts the user to enter the name of the book to edit. If the book is found in the collection,
 * the function allows the user to modify the book's name, author, and publish date. The user can choose to keep
 * the current values for any of these fields by pressing enter without entering any new value. The function then
 * updates the book's details accordingly. If the book is not found in the collection, the function displays a
 * "Book not found!" message.
 */
void editBook(vector<Book*>& books) {
    string bookName;
    cout << "Enter the name of the book to edit: ";
    cin.ignore();
    getline(cin, bookName);

    for (auto& book : books) {
        if (book->name == bookName) {
            cout << "Enter new book name (or press enter to keep the current one): ";
            string newName;
            getline(cin, newName);
            if (!newName.empty()) book->name = newName;

            cout << "Enter new author name (or press enter to keep the current one): ";
            string newAuthor;
            getline(cin, newAuthor);
            if (!newAuthor.empty()) book->author = newAuthor;

            valid_date:
            cout << "Enter new publish date (DD MM YYYY) or 0 0 0 to keep the current one: ";
            int day, month, year;
            cin >> day >> month >> year;
            if (isValidDate(day, month, year) || (day != 0 || month != 0 || year != 0)) {
                book->publish_date = {day, month, year};
            } else {
                cout << "enter a valid date: " << endl;
                goto valid_date;
            }

            cout << "Book edited successfully!" << endl;
            return;
        }
    }
    cout << "Book not found!" << endl;
}

/**
 * Removes a book from the vector of books.
 * 
 * @param books The vector of books.
 */
void removeBook(vector<Book*>& books) {
    string bookName;
    cout << "Enter the name of the book to remove: ";
    cin.ignore();
    getline(cin, bookName);

    for (auto it = books.begin(); it != books.end(); ++it) {
        if ((*it)->name == bookName) {
            delete *it; // Free memory of the book
            books.erase(it); // Remove the pointer from the vector
            cout << "Book removed successfully!" << endl;
            return;
        }
    }
    cout << "Book not found!" << endl;
}

/**
 * @brief Clears the inventory of books.
 * 
 * This function deletes all the books in the given vector and clears the vector.
 * It also prints a message to indicate that the inventory has been cleared.
 * 
 * @param books A vector of Book pointers representing the inventory.
 */
void clearInventory(vector<Book*>& books) {
    for (auto& book : books) {
        delete book; // Free memory for each book
    }
    books.clear(); // Clear the vector
    cout << "Inventory cleared!" << endl;
}

/**
 * @brief The main function of the Library Management System.
 * 
 * This function serves as the entry point of the program. It initializes a vector of books,
 * adds predefined books to the inventory, and presents a menu of options to the user.
 * The user can perform operations such as showing the inventory, adding a book, editing a book,
 * removing a book, and quitting the program.
 * 
 * @return 0 indicating successful program execution.
 */
int main() {
    char userInput=' ';
    vector<Book*> books;
    char& optn = userInput;

    // Add predefined books
    books.push_back(new Book{"To Kill a Mockingbird", "Harper Lee", {11, 7, 1960}});
    books.push_back(new Book{"1984", "George Orwell", {8, 6, 1949}});
    books.push_back(new Book{"The Great Gatsby", "F. Scott Fitzgerald", {10, 4, 1925}});
    books.push_back(new Book{"Pride and Prejudice", "Jane Austen", {28, 1, 1813}});
    books.push_back(new Book{"The Catcher in the Rye", "J.D. Salinger", {16, 7, 1951}});

    while (optn) {
        cout << endl << "+-+-+-+( Library Management System )+-+-+-+" << endl;
        cout << "+ (z) : show whole inventory              +" << endl;
        cout << "+ (s) : show a book                       +" << endl;
        cout << "+ (a) : add a book                        +" << endl;
        cout << "+ (e) : edit a book                       +" << endl;
        cout << "+ (r) : remove a book                     +" << endl;
        cout << "+ (c) : clear inventory                   +" << endl;
        cout << "+ (x) : clear output buffer               +" << endl;
        cout << "+ (q) : quit()                            +" << endl;
        cout << "+-+-+-+( x - x - x - x - x - x - x )+-+-+-+" << endl;

        switch_start:
        cout << " ~ $ : ";
        cin >> userInput;

        switch (userInput) {
            case 'z':
                showInventory(books);
                goto switch_start;
            case 's':
                showBook(books);
                goto switch_start;
            case 'a':
                addBook(books);
                goto switch_start;
            case 'e':
                editBook(books);
                goto switch_start;
            case 'r':
                removeBook(books);
                break;
            case 'c':
                clearInventory(books);
                goto switch_start;
            case 'x':
#ifdef _WIN32
                system("CLS");
#else
                system("clear");
#endif
                break;
            case 'q':
                clearInventory(books); // Ensure all memory is freed before quitting
                cout << "(-/ quitting.. /-)" << endl;
                return 0;
            default:
                cout << "Enter a valid operation." << endl;
                goto switch_start;
        }
    }

    return 0;
}
