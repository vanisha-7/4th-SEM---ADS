#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

// Initialize table
void init() {
    for(int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

// Hash function
int hash(int key) {
    return key % SIZE;
}

// Insert using Linear Probing
void insert(int key) {
    int index = hash(key);

    while(hashTable[index] != -1) {
        index = (index + 1) % SIZE; // move to next slot
    }

    hashTable[index] = key;
}

// Display table
void display() {
    for(int i = 0; i < SIZE; i++) {
        if(hashTable[i] != -1)
            printf("%d --> %d\n", i, hashTable[i]);
        else
            printf("%d --> NULL\n", i);
    }
}

int main() {
    init();

    insert(10);
    insert(20);
    insert(30);
    insert(25); // collision handled

    display();
    return 0;
}