#include "PrintedBook.h"

PrintedBook::PrintedBook(std::string t, std::string a, Genre g, int pages) : Book(t, a, g), pageCount(pages) {}
void PrintedBook::displayInfo() const {
    Book::displayInfo();
    std::cout << ", Page Count: " << pageCount;
}
std::string PrintedBook::getPageCount() const {
    return std::to_string(pageCount);
}