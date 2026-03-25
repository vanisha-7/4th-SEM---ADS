#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// Node structure
struct node {
    int data;
    struct node* next;
};

struct node* hashTable[SIZE];

// Hash function
int hash(int key) {
    return key % SIZE;
}

// Insert using chaining
void insert(int key) {
    int index = hash(key);

    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = key;
    newNode->next = NULL;

    if(hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        struct node* temp = hashTable[index];
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Display table
void display() {
    for(int i = 0; i < SIZE; i++) {
        struct node* temp = hashTable[i];
        printf("%d --> ", i);
        while(temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    for(int i = 0; i < SIZE; i++)
        hashTable[i] = NULL;

    insert(10);
    insert(20);
    insert(30);
    insert(25); // collision handled

    display();
    return 0;
}