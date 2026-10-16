#pragma once

#include "Book.h"
#include <string>

class PrintedBook : public Book {
    int pageCount;
public:
    PrintedBook(std::string t, std::string a, Genre g, int pages);
    void displayInfo() const override;
    std::string getPageCount() const;
};