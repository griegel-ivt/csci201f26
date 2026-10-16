#include "Patron.h"

Patron::Patron(std::string n, int i) {
    name = n;
    id = i;
}
void Patron::borrowBook(Book* b) {
    borrowedBooks.push_back(b);
}
void Patron::returnBook(Book* b) {
    borrowedBooks.erase(std::remove(borrowedBooks.begin(), borrowedBooks.end(), b), borrowedBooks.end());
}
void Patron::displayPatron() const {
    std::cout << "Patron: " << name << ", ID: " << id << ", Borrowed Books: ";
    for (const Book* book : borrowedBooks) {
        std::cout << book->getTitle() << "; ";
    }
}
std::string Patron::getName() const {
    return name;
}
int Patron::getId() const {
    return id;
}

bool Patron::operator==(const Patron& other) const {
    return id == other.id && name == other.name;
}
std::ostream& operator<<(std::ostream& os, const Patron& p) {
    os << "Patron: " << p.getName() << ", ID: " << p.getId();
    return os;
}