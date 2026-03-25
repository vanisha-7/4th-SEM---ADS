#include <stdio.h>

#define SIZE 100

int heap[SIZE];
int n = 0;

// Insert into Max Heap
void insertMax(int value) {
    int i = n++;
    heap[i] = value;

    // Heapify up
    while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
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
    insertMax(10);
    insertMax(20);
    insertMax(5);
    insertMax(30);

    printf("Max Heap: ");
    display();

    return 0;
}