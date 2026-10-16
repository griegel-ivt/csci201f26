#pragma once

#include <ctime>
#include <string>
#include <iostream>

class Transaction {
    int patronId;
    std::string bookTitle;
    std::string date;
    std::string transactionType;
public:
    Transaction(int pid, std::string bt, std::string tt);
    void displayTransaction() const;
};