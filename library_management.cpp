#include <stdio.h>
#include <string.h>
#define MAX 100

struct Book {
    char title[50];
    char author[50];
    int isbn;
};

struct Book b[MAX];
int n = 0;

void insertData() {
    if (n >= MAX) {
        printf("Database full!\n");
        return;
    }

    printf("Enter Title: ");
    scanf(" %[^\n]", b[n].title);

    printf("Enter Author: ");
    scanf(" %[^\n]", b[n].author);

    printf("Enter ISBN: ");
    scanf("%d", &b[n].isbn);

    n++;
    printf("Book inserted successfully!\n");
}

void display() {
    if (n == 0) {
        printf("No records available.\n");
        return;
    }

    printf("\n%-20s %-20s %-10s\n", "Title", "Author", "ISBN");
    printf("----------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%-20s %-20s %-10d\n",
               b[i].title, b[i].author, b[i].isbn);
    }
}

void sortByTitle() {
    struct Book temp;

    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(b[j].title, b[min].title) < 0) {
                min = j;
            }
        }
        temp = b[i];
        b[i] = b[min];
        b[min] = temp;
    }

    printf("Books sorted by title successfully!\n");
}

void sortByISBN() {
    struct Book temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (b[i].isbn > b[j].isbn) {
                temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }
}

void searchByISBN() {
    if (n == 0) {
        printf("No records available.\n");
        return;
    }

    int key;
    printf("Enter ISBN to search: ");
    scanf("%d", &key);

    sortByISBN();

    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (b[mid].isbn == key) {
            printf("\nBook Found!\n");
            printf("Title: %s\nAuthor: %s\nISBN: %d\n",
                   b[mid].title, b[mid].author, b[mid].isbn);
            return;
        }
        else if (b[mid].isbn < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    printf("Book not found.\n");
}

int main() {
    int choice;

    do {
        printf("\n===== LIBRARY MANAGEMENT SYSTEM =====\n");
        printf("1. Insert Book\n");
        printf("2. Display Books\n");
        printf("3. Sort Books by Title (Selection Sort)\n");
        printf("4. Search Book by ISBN (Binary Search)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertData();
                break;

            case 2:
                display();
                break;

            case 3:
                sortByTitle();
                break;

            case 4:
                searchByISBN();
                break;

            case 5:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 5);
    return 0;
}
