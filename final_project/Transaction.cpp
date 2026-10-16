#include "Transaction.h"
Transaction::Transaction(int pid, std::string bt, std::string tt) : patronId(pid), bookTitle(bt), transactionType(tt) {
    std::time_t now = std::time(nullptr);
    char buffer[100];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
    date = buffer;
}
void Transaction::displayTransaction() const {
    std::cout << "Date: " << date << ", Patron ID: " << patronId << ", Book Title: " << bookTitle << ", Transaction Type: " << transactionType;
}