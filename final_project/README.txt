Features

- Polymorphic Book Hierarchy: Supports both PrintedBook (page counts) and EBook (file sizes in MB) derived from a common Book base class.

- Persistence: Automatically loads existing inventory and patron details from Books.txt and Patrons.txt on startup and saves on exit.

- Patron and Inventory Management: Allows adding new books and patrons, displaying all records, and managing borrowing status.

- Checkout and Return Logic: Updates availability statuses and associates borrowed items directly with patron accounts.

- Automated Transaction Logging: Logs checkouts and returns with real time stamps.

===================
SAMPLE USAGE
===================

Menu Input:
1

Program Output:
----- Books -----
Title: To Kill a Mockingbird, Author: Harper Lee, Genre: Fiction, Status: Available, Page Count: 281
Title: Dune, Author: Frank Herbert, Genre: Science, Status: Available, File Size: 2.5 MB
Title: The Great Gatsby, Author: F. Scott Fitzgerald, Genre: Fiction, Status: Available, Page Count: 180

===================
Menu Input:
3
Enter Patron ID: 0
Enter Book Title: Dune

Program Output:
(Reflected upon viewing Books or Patrons)

===================
Menu Input:
6
Please Enter Book Type (1. Printed, 2. EBook): 1
Enter Title: 1984
Enter Author: George Orwell
Please Select Book Genre (0: Fiction, 1: Non-Fiction, 2: Mystery, 3: Science, 4: Biography, 5: Miscellaneous): 0
Enter Page Count: 328

Program Output:
(Reflected upon viewing Books or Patrons)
