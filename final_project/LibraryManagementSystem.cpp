#include "PrintedBook.h"
#include "EBook.h"
#include "Library.h"
#include "Patron.h"
#include "Transaction.h"

#include <iostream>
#include <string>

void displayMenu() {
    std::cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
    std::cout << "1. Display Books\n";
    std::cout << "2. Display Patrons\n";
    std::cout << "3. Checkout Book\n";
    std::cout << "4. Return Book\n";
    std::cout << "5. View Transaction History\n";
    std::cout << "6. Add New Book\n";
    std::cout << "7. Add New Patron\n";
    std::cout << "8. Exit and Save\n";
    std::cout << "Enter your choice (1-8): ";
}

int main() {
    Library library;

    // Load data from files
    library.loadData();

    int choice;
    while (choice != 8) {
        displayMenu();
        if (!(std::cin >> choice)) {
            std::cerr << "Invalid input. Please enter a number between 1 and 8." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // I had to ask AI about this because it kept doing weird things with my input that I hadn't experienced in the Zybooks.
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // And this is the other part I had to ask AI about because it kept skipping input prompts after the first one.

        switch (choice) {
            case 1:
                std::cout << "\n----- Books -----\n";
                library.displayBooks();
                break;
            case 2:
            std::cout << "\n----- Patrons -----\n";
                library.displayPatrons();
                break;
            case 3: {
                int patronId;
                std::string title;
                std::cout << "Enter Patron ID: ";
                std::cin >> patronId;
                std::cin.ignore();
                std::cout << "Enter Book Title: ";
                std::getline(std::cin, title);
                
                library.checkoutBook(patronId, title);
                break;
            }
            case 4: {
                int patronId;
                std::string title;
                std::cout << "Enter Patron ID: ";
                std::cin >> patronId;
                std::cin.ignore();
                std::cout << "Enter Book Title: ";
                std::getline(std::cin, title);

                library.returnBook(patronId, title);
                break;
            }
            case 5:
                std::cout << "\n----- Transaction History -----\n";
                library.displayTransactions();
                break;
            case 6: {
                int typeChoice;
                std::string title, author;
                int genreInt;
                
                std::cout << "Please Enter Book Type (1. Printed, 2. EBook): ";
                std::cin >> typeChoice;
                std::cin.ignore();
                
                std::cout << "Enter Title: ";
                std::getline(std::cin, title);
                std::cout << "Enter Author: ";
                std::getline(std::cin, author);
                
                std::cout << "Please Select Book Genre (0: Fiction, 1: Non-Fiction, 2: Mystery, 3: Science, 4: Biography, 5: Miscellaneous): ";
                std::cin >> genreInt;
                Genre g = static_cast<Genre>(genreInt);

                if (typeChoice == 1) {
                    int pages;
                    std::cout << "Enter Page Count: ";
                    std::cin >> pages;
                    library.addBook(new PrintedBook(title, author, g, pages));
                } else {
                    double size;
                    std::cout << "Enter File Size (MB): ";
                    std::cin >> size;
                    library.addBook(new EBook(title, author, g, size));
                }
                break;
            }
            case 7: {
                std::string name;
                int id;
                std::cout << "Please Enter Patron Name: ";
                std::getline(std::cin, name);
                std::cout << "Enter Patron ID: ";
                std::cin >> id;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // And another... this really was a magic line.

                library.addPatron(Patron(name, id));
                break;
            }
            case 8:
                library.saveData();
                std::cout << "Data saved successfully. Exiting...\n";
                break;
        }
    }
    return 0;
}