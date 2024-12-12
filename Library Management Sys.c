/*
Solution Plan:
1. Define a structure `Book` to store book details (ID, title, author, and availability).
2. Implement functions to:
   - Add a new book.
   - Display all books.
   - Borrow a book by ID.
   - Return a book by ID.
3. Use a menu-driven interface for user interaction.
*/

#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

// Define the structure for storing book details
typedef struct {
    int id;
    char title[100];
    char author[100];
    int isAvailable; // 1 if available, 0 if borrowed
} Book;

Book library[MAX_BOOKS]; // Array to store books
int bookCount = 0;       // Tracks the number of books

// Function to add a new book
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }

    Book newBook;

    printf("Enter Book ID: ");
    scanf("%d", &newBook.id);
    getchar(); // Consume newline character

    printf("Enter Book Title: ");
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // Remove newline character

    printf("Enter Book Author: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; // Remove newline character

    newBook.isAvailable = 1; // Book is available when added
    library[bookCount++] = newBook;

    printf("Book added successfully!\n\n");
}

// Function to display all books
void displayBooks() {
    if (bookCount == 0) {
        printf("No books available in the library!\n\n");
        return;
    }

    printf("\n--- Library Books ---\n");
    for (int i = 0; i < bookCount; i++) {
        printf("ID: %d\n", library[i].id);
        printf("Title: %s\n", library[i].title);
        printf("Author: %s\n", library[i].author);
        printf("Status: %s\n\n", library[i].isAvailable ? "Available" : "Borrowed");
    }
}

// Function to borrow a book by ID
void borrowBook() {
    int id;
    printf("Enter Book ID to borrow: ");
    scanf("%d", &id);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            if (library[i].isAvailable) {
                library[i].isAvailable = 0;
                printf("Book borrowed successfully!\n\n");
            } else {
                printf("Book is already borrowed!\n\n");
            }
            return;
        }
    }
    printf("Book with ID %d not found!\n\n", id);
}

// Function to return a book by ID
void returnBook() {
    int id;
    printf("Enter Book ID to return: ");
    scanf("%d", &id);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            if (!library[i].isAvailable) {
                library[i].isAvailable = 1;
                printf("Book returned successfully!\n\n");
            } else {
                printf("Book was not borrowed!\n\n");
            }
            return;
        }
    }
    printf("Book with ID %d not found!\n\n", id);
}

// Main function
int main() {
    int choice;

    do {
        // Display the menu
        printf("\n--- Library Management System ---\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Borrow Book\n");
        printf("4. Return Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                borrowBook();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
