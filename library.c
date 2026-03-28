#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    char author[50];
    int isIssued; // 0 = Available, 1 = Issued
};

struct Book books[100]; // maximum 100 books
int count = 0; // number of books

// Add a new book
void addBook() {
    if(count >= 100) {
        printf("Library full! Cannot add more books.\n");
        return;
    }
    printf("Enter Book ID: ");
    scanf("%d", &books[count].id);

    printf("Enter Title: ");
    scanf(" %[^\n]", books[count].title);

    printf("Enter Author: ");
    scanf(" %[^\n]", books[count].author);

    books[count].isIssued = 0;
    count++;

    printf("Book added successfully!\n");
}

// Display all books
void displayBooks() {
    if(count == 0) {
        printf("No books in library yet!\n");
        return;
    }

    printf("\n----- Book List -----\n");
    for(int i=0; i<count; i++) {
        printf("\nID: %d\nTitle: %s\nAuthor: %s\nStatus: %s\n",
               books[i].id, books[i].title, books[i].author,
               books[i].isIssued ? "Issued" : "Available");
    }
}

// Search for a book by ID
void searchBook() {
    int id, found = 0;
    printf("Enter Book ID to search: ");
    scanf("%d", &id);

    for(int i=0; i<count; i++) {
        if(books[i].id == id) {
            printf("\nBook Found:\n");
            printf("Title: %s\nAuthor: %s\nStatus: %s\n",
                   books[i].title, books[i].author,
                   books[i].isIssued ? "Issued" : "Available");
            found = 1;
            break;
        }
    }

    if(!found)
        printf("Book not found!\n");
}

// Issue a book by ID
void issueBook() {
    int id, found = 0;
    printf("Enter Book ID to issue: ");
    scanf("%d", &id);

    for(int i=0; i<count; i++) {
        if(books[i].id == id) {
            if(books[i].isIssued) {
                printf("Book already issued!\n");
            } else {
                books[i].isIssued = 1;
                printf("Book issued successfully!\n");
            }
            found = 1;
            break;
        }
    }

    if(!found)
        printf("Book not found!\n");
}

// Return a book by ID
void returnBook() {
    int id, found = 0;
    printf("Enter Book ID to return: ");
    scanf("%d", &id);

    for(int i=0; i<count; i++) {
        if(books[i].id == id) {
            if(books[i].isIssued) {
                books[i].isIssued = 0;
                printf("Book returned successfully!\n");
            } else {
                printf("Book was not issued.\n");
            }
            found = 1;
            break;
        }
    }

    if(!found)
        printf("Book not found!\n");
}

int main() {
    int choice;

    do {
        printf("\n===== LIBRARY MANAGEMENT SYSTEM =====\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 6);

    return 0;
}
