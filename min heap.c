#include <stdio.h>

#define SIZE 100

int heap[SIZE];
int n = 0;

// Insert into Min Heap
void insertMin(int value) {
    int i = n++;
    heap[i] = value;

    // Heapify up
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

// Display heap
void display() {
    for (int i = 0; i < n; i++)
        printf("%d ", heap[i]);
}

int main() {
    insertMin(10);
    insertMin(20);
    insertMin(5);
    insertMin(30);

    printf("Min Heap: ");
    display();

    return 0;
}