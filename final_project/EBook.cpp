#include "EBook.h"

EBook::EBook(std::string t, std::string a, Genre g, double size) : Book(t, a, g), fileSizeMB(size) {}
void EBook::displayInfo() const {
    Book::displayInfo();
    std::cout << ", File Size: " << fileSizeMB << " MB";
}
std::string EBook::getFileSize() const {
    return std::to_string(fileSizeMB);
}