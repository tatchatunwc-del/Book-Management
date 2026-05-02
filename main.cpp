class Book {
protected:
    string title, author, isbn;
    bool availability;

public:
    Book() {}

    Book(string t, string a, string i) {
        title = t;
        author = a;
        isbn = i;
        availability = true;
    }

    virtual void displayBookDetails() {
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

    string getISBN() {
        return isbn;
    }
};

class HardcopyBook : public Book {
private:
    string shelfNumber;

public:
    HardcopyBook(string t, string a, string i, string shelf)
        : Book(t, a, i) {
        shelfNumber = shelf;
    }

    void displayBookDetails() override {
        Book::displayBookDetails();
        cout << "Shelf: " << shelfNumber << endl;
    }
};

class EBook : public Book {
private:
    string licenseEndDate;

public:
    EBook(string t, string a, string i, string date)
        : Book(t, a, i) {
        licenseEndDate = date;
    }

    void displayBookDetails() override {
        Book::displayBookDetails();
        cout << "License Ends: " << licenseEndDate << endl;
    }
};
