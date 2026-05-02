class HardcopyBook : public Book {
private:
    string shelfNumber;

public:
    void setShelf(string s) {
        shelfNumber = s;
    }
};

class EBook : public Book {
private:
    string licenseEndDate;

public:
    void setLicense(string d) {
        licenseEndDate = d;
    }
};
