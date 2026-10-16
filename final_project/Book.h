#pragma once

#include <string>
#include <iostream>

enum class Genre { Fiction, NonFiction, Mystery, Science, Biography, Miscellaneous };
enum class BookStatus { Available, CheckedOut };

class Book {
protected:
    std::string title;
    std::string author;
    Genre genre;
    BookStatus status;
public:
    Book(std::string t, std::string a, Genre g);
    virtual ~Book() = default;

    virtual void displayInfo() const;
    void setStatus(BookStatus s);
    BookStatus getStatus() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    Genre getGenre() const;

    bool operator==(const Book& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Book& b);
};