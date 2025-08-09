#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int items[MAX];
    int size;
} Heap;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(Heap *h, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < h->size && h->items[left] < h->items[smallest]) smallest = left;
    if (right < h->size && h->items[right] < h->items[smallest]) smallest = right;
    if (smallest != i) {
        swap(&h->items[i], &h->items[smallest]);
        minHeapify(h, smallest);
    }
}

void maxHeapify(Heap *h, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < h->size && h->items[left] > h->items[largest]) largest = left;
    if (right < h->size && h->items[right] > h->items[largest]) largest = right;
    if (largest != i) {
        swap(&h->items[i], &h->items[largest]);
        maxHeapify(h, largest);
    }
}

void buildMinHeap(Heap *h) {
    for (int i = h->size / 2 - 1; i >= 0; i--) minHeapify(h, i);
}

void buildMaxHeap(Heap *h) {
    for (int i = h->size / 2 - 1; i >= 0; i--) maxHeapify(h, i);
}

void printHeap(Heap *h) {
    for (int i = 0; i < h->size; i++) printf("%d ", h->items[i]);
    printf("\n");
}

int main() {
    Heap h;
    int arr[] = {4, 10, 3, 5, 1};
    h.size = 5;
    for (int i = 0; i < h.size; i++) h.items[i] = arr[i];
    printf("Original array: ");
    printHeap(&h);
    buildMinHeap(&h);
    printf("Min Heap: ");
    printHeap(&h);
    for (int i = 0; i < h.size; i++) h.items[i] = arr[i];
    buildMaxHeap(&h);
    printf("Max Heap: ");
    printHeap(&h);
    return 0;
}