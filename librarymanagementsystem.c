#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    char author[TITLE_LENGTH];
    int year;
} Book;

Book library[MAX_BOOKS];
int bookCount = 0;

void addBook() {
    if (bookCount < MAX_BOOKS) {
        printf("Enter book title: ");
        scanf(" %[^\n]%*c", library[bookCount].title);
        printf("Enter author: ");
        scanf(" %[^\n]%*c", library[bookCount].author);
        printf("Enter year of publication: ");
        scanf("%d", &library[bookCount].year);
        bookCount++;
        printf("Book added successfully!\n");
    } else {
        printf("Library is full!\n");
    }
}

void viewBooks() {
    if (bookCount == 0) {
        printf("No books in the library.\n");
        return;
    }
    printf("\nList of books:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("Title: %s, Author: %s, Year: %d\n",
               library[i].title, library[i].author, library[i].year);
    }
}

void searchBook() {
    char searchTitle[TITLE_LENGTH];
    printf("Enter the title of the book to search: ");
    scanf(" %[^\n]%*c", searchTitle);

    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].title, searchTitle) == 0) {
            printf("Book found: Title: %s, Author: %s, Year: %d\n",
                   library[i].title, library[i].author, library[i].year);
            return;
        }
    }
    printf("Book not found.\n");
}

int main() {
    int choice;

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Search Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                viewBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
