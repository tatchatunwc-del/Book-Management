#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    bool availability;

public:
    void setBookDetails(string t, string a, string i, bool available) {
        title = t;
        author = a;
        isbn = i;
        availability = available;
    }

    void displayBookDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Status: " << (availability ? "Available" : "Borrowed") << endl;
        cout << "-----------------------------" << endl;
    }

    string getISBN() {
        return isbn;
    }

    bool borrowBook() {
        if (availability) {
            availability = false;
            return true;
        }
        return false;
    }

    void returnBook() {
        availability = true;
    }
};

int main() {
    Book books[5];

    books[0].setBookDetails("The Great Gatsby", "F. Scott Fitzgerald", "1001", true);
    books[1].setBookDetails("To Kill a Mockingbird", "Harper Lee", "1002", true);
    books[2].setBookDetails("1984", "George Orwell", "1003", false);
    books[3].setBookDetails("Pride and Prejudice", "Jane Austen", "1004", true);
    books[4].setBookDetails("The Hobbit", "J.R.R. Tolkien", "1005", true);

    string inputISBN;

    cout << "Library Book Borrowing System" << endl;
    cout << "=============================" << endl;

    while (true) {
        cout << "\nBook List:" << endl;
        cout << "-----------------------------" << endl;

        for (int i = 0; i < 5; i++) {
            books[i].displayBookDetails();
        }

        cout << "Enter ISBN to borrow a book (Enter 0 to exit): ";
        cin >> inputISBN;

        if (inputISBN == "0") {
            cout << "Program ended. Thank you!" << endl;
            break;
        }

        bool found = false;

        for (int i = 0; i < 5; i++) {
            if (books[i].getISBN() == inputISBN) {
                found = true;

                if (books[i].borrowBook()) {
                    cout << "Book borrowed successfully!" << endl;
                } else {
                    cout << "Error: This book is already borrowed." << endl;
                }

                break;
            }
        }

        if (!found) {
            cout << "Error: Book not found." << endl;
        }
    }

    return 0;
}