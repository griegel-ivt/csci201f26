#include "Book.h"

Book::Book(std::string t, std::string a, Genre g) {
    title = t;
    author = a;
    if (g == Genre::Fiction || g == Genre::NonFiction || g == Genre::Mystery || g == Genre::Science || g == Genre::Biography) {
        genre = g;
    } else {
        genre = Genre::Miscellaneous;
    }
    status = BookStatus::Available;
}

void Book::displayInfo() const {
    std::cout << *this;
}

void Book::setStatus(BookStatus s) {
    if (s == BookStatus::CheckedOut) {
        status = s;
    } else {
        status = BookStatus::Available;
    }
}
BookStatus Book::getStatus() const {
    return status;
}
std::string Book::getTitle() const {
    return title;
}
std::string Book::getAuthor() const {
    return author;
}
Genre Book::getGenre() const {
    return genre;
}

bool Book::operator==(const Book& other) const {
    return title == other.title && author == other.author && genre == other.genre;
}
std::ostream& operator<<(std::ostream& os, const Book& b) {
    os << "Title: " << b.title << ", Author: " << b.author << ", Genre: ";
    switch (b.genre) {
        case Genre::Fiction:
            os << "Fiction";
            break;
        case Genre::NonFiction:
            os << "Non-Fiction";
            break;
        case Genre::Mystery:
            os << "Mystery";
            break;
        case Genre::Science:
            os << "Science";
            break;
        case Genre::Biography:
            os << "Biography";
            break;
        default:
            os << "Miscellaneous";
            break;
    }
    switch (b.status) {
        case BookStatus::Available:
            os << ", Status: Available";
            break;
        case BookStatus::CheckedOut:
            os << ", Status: Checked Out";
            break;
    }
    return os;
}