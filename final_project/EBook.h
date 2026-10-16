#pragma once

#include "Book.h"
#include <string>

class EBook : public Book {
    double fileSizeMB;
public:
    EBook(std::string t, std::string a, Genre g, double size);
    void displayInfo() const override;
    std::string getFileSize() const;
};