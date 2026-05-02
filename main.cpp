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
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Status: " << (availability ? "Available" : "Borrowed") << endl;
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

    string getISBN() {
        return isbn;
    }

    bool isAvailable() {
        return availability;
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

    void displayAllBooks() {
        for (int i = 0; i < bookCount; i++) {
            books[i].displayBookDetails();
            cout << "-------------------" << endl;
        }
    }

    int findBook(string isbn) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].getISBN() == isbn)
                return i;
        }
        return -1;
    }

    void borrowBook(string isbn) {
        int index = findBook(isbn);
        if (index == -1) {
            cout << "Book not found" << endl;
        } else if (books[index].borrowBook()) {
            cout << "Borrowed successfully" << endl;
        } else {
            cout << "Already borrowed" << endl;
        }
    }
};

int main() {
    Library lib;

    Book b1, b2;
    b1.setBookDetails("1984", "George Orwell", "1001");
    b2.setBookDetails("Hobbit", "Tolkien", "1002");

    lib.addBook(b1);
    lib.addBook(b2);

    string isbn;

    while (true) {
        lib.displayAllBooks();
        cout << "Enter ISBN (0 to exit): ";
        cin >> isbn;

        if (isbn == "0") break;

        lib.borrowBook(isbn);
    }

    return 0;
}
