#include "Library.h"

Library::~Library() {
    for (Book* book : books) {
        delete book;
    }
}
void Library::loadData() {
    std::ifstream file1("Books.txt");
    if (!file1.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    std::string line1;
    while (std::getline(file1, line1)) {
        std::stringstream ss(line1);
        std::string title, author, genreStr, type, num;

        std::getline(ss, genreStr, ',');
        std::getline(ss, title, ',');
        std::getline(ss, author, ',');
        std::getline(ss, type, ',');
        std::getline(ss, num, ',');

        Genre genre;
        if (genreStr == "Fiction") genre = Genre::Fiction;
        else if (genreStr == "Non-Fiction") genre = Genre::NonFiction;
        else if (genreStr == "Mystery") genre = Genre::Mystery;
        else if (genreStr == "Science") genre = Genre::Science;
        else if (genreStr == "Biography") genre = Genre::Biography;
        else genre = Genre::Miscellaneous;

        if (type == "Printed") {
            int pageCount = std::stoi(num);
            books.push_back(new PrintedBook(title, author, genre, pageCount));
        } else if (type == "EBook") {
            double fileSize = std::stod(num);
            books.push_back(new EBook(title, author, genre, fileSize));
        }
    }

    file1.close();

    std::ifstream file2("Patrons.txt");
    if (!file2.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    std::string line2;
    while (std::getline(file2, line2)) {
        std::stringstream ss(line2);
        std::string idStr, name;

        std::getline(ss, idStr, ',');
        std::getline(ss, name, ',');

        int id = std::stoi(idStr);
        patrons.push_back(Patron(name, id));
    }

    file2.close();
}
void Library::saveData() {
    std::ofstream file1("Books.txt");
    if (!file1.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    for (const Book* book : books) {
        const PrintedBook* pBook = dynamic_cast<const PrintedBook*>(book);
        const EBook* eBook = dynamic_cast<const EBook*>(book);

        std::string genreStr;
        switch (book->getGenre()) {
            case Genre::Fiction:
                genreStr = "Fiction";
                break;
            case Genre::NonFiction:
                genreStr = "Non-Fiction";
                break;
            case Genre::Mystery:
                genreStr = "Mystery";
                break;
            case Genre::Science:
                genreStr = "Science";
                break;
            case Genre::Biography:
                genreStr = "Biography";
                break;
            default:
                genreStr = "Miscellaneous";
                break;
        }
        if (pBook) {
            file1 << genreStr << "," << pBook->getTitle() << "," << pBook->getAuthor() << "," << "Printed," << pBook->getPageCount() << std::endl;
        } else if (eBook) {
            file1 << genreStr << "," << eBook->getTitle() << "," << eBook->getAuthor() << "," << "EBook,"<< eBook->getFileSize() << std::endl;
        }
    }

    file1.close();

    std::ofstream file2("Patrons.txt");
    if (!file2.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    for (const Patron& patron : patrons) {
        file2 << patron.getId() << "," << patron.getName() << std::endl;
    }

    file2.close();
}
void Library::addBook(Book* b) {
    books.push_back(b);
}
void Library::addPatron(const Patron& p) {
    patrons.push_back(p);
}
void Library::checkoutBook(int patronId, std::string title) {
    if (patronId < 0 || patronId >= patrons.size()) {
        std::cerr << "Invalid patron ID." << std::endl;
        return;
    } else {
        Patron& patron = patrons[patronId];
        for (Book* book : books) {
            if (book->getStatus() == BookStatus::Available && book->getTitle() == title) {
                patron.borrowBook(book);
                book->setStatus(BookStatus::CheckedOut);
                return;
            }
        }
        std::cerr << "Book not available." << std::endl;
    }
    transactions.push_back(Transaction(patronId, title, "Checkout"));
}
void Library::returnBook(int patronId, std::string title) {
    if (patronId < 0 || patronId >= patrons.size()) {
        std::cerr << "Invalid patron ID." << std::endl;
        return;
    } else {
        Patron& patron = patrons[patronId];
        for (Book* book : books) {
            if (book->getStatus() == BookStatus::CheckedOut && book->getTitle() == title) {
                patron.returnBook(book);
                book->setStatus(BookStatus::Available);
                return;
            }
        }
        std::cerr << "Book not found in patron's borrowed list." << std::endl;
    }
    transactions.push_back(Transaction(patronId, title, "Return"));
}
void Library::displayBooks() const {
    for (const Book* book : books) {
        book->displayInfo();
        std::cout << std::endl;
    }
}
void Library::displayPatrons() const {
    for (const Patron& patron : patrons) {
        patron.displayPatron();
        std::cout << std::endl;
    }
}
void Library::displayTransactions() const {
    for (const Transaction& transaction : transactions) {
        transaction.displayTransaction();
        std::cout << std::endl;
    }
}