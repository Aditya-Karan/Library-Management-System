#include <stdio.h>
#include <string.h>


struct Book {
    int id;
    char title[50];
    char author[50];
};

struct Library {
    struct Book books[100];
    int numBooks;
};

void addBook(struct Library *library) {
    if (library->numBooks == 100) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }

    struct Book newBook;
    printf("Enter book ID: ");
    scanf("%d", &newBook.id);
    printf("Enter book title: ");
    scanf(" %s", newBook.title);
    printf("Enter book author: ");
    scanf(" %s", newBook.author);

    library->books[library->numBooks] = newBook;
    library->numBooks++;

    printf("Book added successfully.\n");
}

void displayBooks(struct Library library) {
    if (library.numBooks == 0) {
        printf("Library is empty. No books to display.\n");
        return;
    }

    printf("Books in the library:\n");
    printf("ID  Title  Author\n");
    for (int i = 0; i < library.numBooks; i++) {
        printf("%d  %s  %s\n", library.books[i].id, library.books[i].title, library.books[i].author);
    }
}

int findBookById(struct Library library, int bookId) {
         printf("Please enter the Book Id :\n");
        scanf("%d",&bookId);
    

        printf("Book Info :\n");
        printf("ID  Title  Author\n");
    for (int i = 0; i < library.numBooks; i++) {
        if (library.books[i].id == bookId) {
           printf("%d  %s  %s\n", library.books[i].id, library.books[i].title, library.books[i].author);
         
        }
        
    }
    
}

int findBookIndex(struct Library library, int bookId) {

    for (int i = 0; i < library.numBooks; i++) {
        if (library.books[i].id == bookId) {
           return i;
        }
    }
    
    return -1;
}

 void removeBook(struct Library *library) {
    int bookId;
    printf("Enter book ID to remove: ");
    scanf("%d", &bookId);

    int bookIndex = findBookIndex(*library, bookId);
    if (bookIndex == -1) {
        printf("Book with ID %d not found in the library.\n", bookId);
        return;
    }

    for (int i = bookIndex; i < library->numBooks - 1; i++) {
        library->books[i] = library->books[i + 1];
    }
    library->numBooks--;

    printf("Book with ID %d removed successfully.\n", bookId);
}

int main() {
    struct Library library;
    library.numBooks = 0;
    int bookId;

    int choice;
    do {
        printf("\nLibrary Management System\n");
        printf("1. Add a book\n");
        printf("2. Display all books\n");
        printf("3. Find Book By Id\n");
        printf("4. Remove a book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(&library);
                break;
            case 2:
                displayBooks(library);
                break;
            case 3:
                findBookById(library,bookId);
                break;
            case 4:
                 removeBook(&library);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

