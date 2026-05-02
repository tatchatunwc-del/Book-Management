#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title, author, isbn;
    bool availability;

public:
    void setBookDetails(string t, string a, string i) {
        title = t;
        author = a;
        isbn = i;
        availability = true;
    }

    void displayBookDetails() {
        cout << title << " - " << author << endl;
    }

    string getISBN() {
        return isbn;
    }
};

class Library {
private:
    Book books[5];
    int bookCount;

public:
    Library() {
        bookCount = 0;
    }

    void addBook(Book b) {
        if (bookCount < 5) {
            books[bookCount++] = b;
        }
    }
};

int main() {
    cout << "Library System Started" << endl;
    return 0;
}
