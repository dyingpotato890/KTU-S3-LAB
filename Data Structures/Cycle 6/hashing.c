#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct Node {
    int data;
    struct Node *next;
};

struct HashTable {
    struct Node *arrayChaining[SIZE];
    int arrayLinearProbing[SIZE];
};

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

struct HashTable *createHashTable() {
    struct HashTable *hashTable = (struct HashTable*) malloc(sizeof(struct HashTable));
    for (int i = 0; i < SIZE; i++) {
        hashTable -> arrayChaining[i] = NULL;
        hashTable -> arrayLinearProbing[i] = -1;
    }
    return hashTable;
}

void insertChaining(struct HashTable *hashTable, int key) {
    int index = key % SIZE;
    struct Node *newNode = createNode(key);
    if (hashTable -> arrayChaining[index] == NULL)
        hashTable -> arrayChaining[index] = newNode;
    else {
        struct Node *current = hashTable -> arrayChaining[index];
        while (current -> next != NULL)
            current = current -> next;
        current -> next = newNode;
    }
}

void insertLinearProbing(struct HashTable *hashTable, int key) {
    int index = key % SIZE;
    while (hashTable -> arrayLinearProbing[index] != -1)
        index = (index + 1) % SIZE;
    hashTable -> arrayLinearProbing[index] = key;
}

void displayChaining(struct HashTable *hashTable) {
    for (int i = 0; i < SIZE; i++) {
        printf("Index %d (Chaining): ", i);
        struct Node *current = hashTable -> arrayChaining[i];
        while (current != NULL) {
            printf("%d -> ", current -> data);
            current = current -> next;
        }
        printf("NULL\n");
    }
}

void displayLinearProbing(struct HashTable *hashTable) {
    printf("KEY\tLOCATION\n");
    printf("-----\t---------\n");

    for (int i = 0; i < SIZE; i++) {
        printf(" %d\t  %d\n", i, hashTable->arrayLinearProbing[i]);
    }
}

void main() {
    struct HashTable *hashTable = createHashTable();
    int choice, key, menuFlag = 1;

    printf("\n\t\t ================== MENU ==================");
    printf("\n\t\t 1) Insert Into Chaining Method");
    printf("\n\t\t 2) Insert Into Linear Probing Method");
    printf("\n\t\t 3) Display Chaining Method");
    printf("\n\t\t 4) Display Linear Probing Method");
    printf("\n\t\t 5) Exit");
    printf("\n\t\t ==========================================");

    while (menuFlag != 0){
        printf("\nEnter Your Choice: ");
        scanf("%d", & choice);
        switch (choice) {
        case 1:
            printf("Enter Key to Insert Using Chaining Method: ");
            scanf("%d", & key);
            insertChaining(hashTable, key);
            break;
        case 2:
            printf("Enter Key to Insert Using Linear Probing Method: ");
            scanf("%d", & key);
            insertLinearProbing(hashTable, key);
            break;
        case 3:
            printf("Hash Table Using Chaining Method:\n");
            displayChaining(hashTable);
            break;
        case 4:
            printf("Hash Table Using Linear Probing Method:\n");
            displayLinearProbing(hashTable);
            break;
        case 5:
            menuFlag = 0;
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option!\n");
        }
    }
}