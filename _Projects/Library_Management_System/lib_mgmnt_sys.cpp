// @Project: Library Management System
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

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
 * Checks if a given year is a leap year.
 * 
 * @param year The year to check.
 * @return True if the year is a leap year, false otherwise.
 */
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
    if ((year < 1 || month < 1 || month > 12 || day < 1)) {
        return false;
    }

    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (month == 2 && isLeapYear(year)) {
        daysInMonth[1] = 29;
    }

    return (day <= daysInMonth[month - 1]);
}

/**
 * Loads books from a CSV file into the inventory.
 * 
 * @param books A vector of Book pointers representing the library's collection of books.
 * @param filename The name of the CSV file to load books from.
 */
void loadBooksFromCSV(vector<Book*>& books, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Could not open file: " << filename << endl;
        return;
    }

    string line;
    if (getline(file, line)) {
        while (getline(file, line)) {
            stringstream ss(line);
            string name, author, date_str, month_str, year_str;

            getline(ss, name, ',');
            getline(ss, author, ',');
            getline(ss, date_str, ',');
            getline(ss, month_str, ',');
            getline(ss, year_str, ',');

            int date = stoi(date_str);
            int month = stoi(month_str);
            int year = stoi(year_str);

            if (isValidDate(date, month, year)) {
                books.push_back(new Book{name, author, date, month, year});
            }
        }
    }

    file.close();
}

/**
 * Saves books from the inventory to a CSV file.
 * 
 * @param books A vector of Book pointers representing the library's collection of books.
 * @param filename The name of the CSV file to save books to.
 */
void saveBooksToCSV(const vector<Book*>& books, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Could not open file: " << filename << endl;
        return;
    }

    for (const auto& book : books) {
        file << book->name << "," << book->author << ","
             << book->publish_date.date << ","
             << book->publish_date.month << ","
             << book->publish_date.year << endl;
    }

    file.close();
}

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
void showBookByName(const vector<Book*>& books) {
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

/**
 * Displays information about books based on the author's name.
 * 
 * @param books A vector of pointers to Book objects.
 */
void showBooksByAuthor(const vector<Book*>& books) {
    string authorName;
    cout << "Enter the author's name: ";
    cin.ignore();
    getline(cin, authorName);

    bool found = false;
    for (const auto& book : books) {
        if (book->author == authorName) {
            cout << "Name: " << book->name << ", Author: " << book->author
                 << ", Publish Date: " << book->publish_date.date << "/"
                 << book->publish_date.month << "/" << book->publish_date.year << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No books found by this author!" << endl;
    }
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

    while (true) {
        cout << "Enter publish date (DD MM YYYY): ";
        cin >> newBook->publish_date.date >> newBook->publish_date.month >> newBook->publish_date.year;
        if (isValidDate(newBook->publish_date.date, newBook->publish_date.month, newBook->publish_date.year)) {
            books.push_back(newBook);
            cout << "Book added successfully!" << endl;
            return;
        } else {
            cout << "Enter a valid date (DD MM YYYY)." << endl;
        }
    }
}

/**
 * @brief Allows the user to edit the details of a book in the library management system.
 * 
 * @param books A vector of pointers to Book objects representing the collection of books.
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

            while (true) {
                cout << "Enter new publish date (DD MM YYYY) or 0 0 0 to keep the current one: ";
                int day, month, year;
                cin >> day >> month >> year;
                if ((day == 0 && month == 0 && year == 0) || isValidDate(day, month, year)) {
                    if (day != 0 || month != 0 || year != 0) {
                        book->publish_date = {day, month, year};
                    }
                    cout << "Book edited successfully!" << endl;
                    return;
                } else {
                    cout << "Enter a valid date." << endl;
                }
            }
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
 * Frees the memory allocated for the books in the library.
 * 
 * @param books A vector of Book pointers representing the library's collection of books.
 */
void cleanup(vector<Book*>& books) {
    for (auto& book : books) {
        delete book;
    }
    books.clear();
}

int main() {
    vector<Book*> books;

    // Load books from CSV file
    loadBooksFromCSV(books, "library_inventory.csv");

    char choice;
    while (true) {
        menu_lvl:
        cout << endl;
        cout << "+-+-+(Library Management System)+-+-+" << endl;
        cout << "+ 1. Show Inventory                 +" << endl;
        cout << "+ 2. Add Book                       +" << endl;
        cout << "+ 3. Edit Book                      +" << endl;
        cout << "+ 4. Remove Book                    +" << endl;
        cout << "+ 5. Show Book by Name              +" << endl;
        cout << "+ 6. Show Books by Author           +" << endl;
        cout << "+ 7. Save and Exit                  +" << endl;
        cout << "+ 0. clear screen                   +" << endl;
        cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
        cout << endl;

        while (true) {
            cout << " ~ $ ";
            cin >> choice;

            switch (choice) {
                case '1':
                    showInventory(books);
                    break;
                case '2':
                    addBook(books);
                    break;
                case '3':
                    editBook(books);
                    break;
                case '4':
                    removeBook(books);
                    break;
                case '5':
                    showBookByName(books);
                    break;
                case '6':
                    showBooksByAuthor(books);
                    break;
                case '0':
#ifdef _WIN32
                    system("CLS");
#else
                    system("clear");
#endif
                    goto menu_lvl;
                case '7':
                    saveBooksToCSV(books, "library_inventory.csv");
                    cleanup(books);
                    cout << "Exiting..." << endl;
                    return 0;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        }
    }

    return 0;
}
