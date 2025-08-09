#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int *arr;
    int size;
    long comparisons, swaps;
} Array;

void initArray(Array *a, int n) {
    a->arr = (int*)malloc(n * sizeof(int));
    a->size = n;
    a->comparisons = a->swaps = 0;
    srand(time(NULL));
    for (int i = 0; i < n; i++) a->arr[i] = rand() % 1000 + 1;
}

void printArray(Array *a) {
    for (int i = 0; i < a->size; i++) printf("%d ", a->arr[i]);
    printf("\n");
}

void bubbleSort(Array *a) {
    for (int i = 0; i < a->size - 1; i++)
        for (int j = 0; j < a->size - i - 1; j++) {
            a->comparisons++;
            if (a->arr[j] > a->arr[j + 1]) {
                a->swaps++;
                int temp = a->arr[j];
                a->arr[j] = a->arr[j + 1];
                a->arr[j + 1] = temp;
            }
        }
}

void selectionSort(Array *a) {
    for (int i = 0; i < a->size - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < a->size; j++) {
            a->comparisons++;
            if (a->arr[j] < a->arr[minIdx]) minIdx = j;
        }
        if (minIdx != i) {
            a->swaps++;
            int temp = a->arr[i];
            a->arr[i] = a->arr[minIdx];
            a->arr[minIdx] = temp;
        }
    }
}

void insertionSort(Array *a) {
    for (int i = 1; i < a->size; i++) {
        int key = a->arr[i];
        int j = i - 1;
        while (j >= 0 && a->arr[j] > key) {
            a->comparisons++;
            a->swaps++;
            a->arr[j + 1] = a->arr[j];
            j--;
        }
        a->comparisons++;
        a->arr[j + 1] = key;
    }
}

void merge(Array *a, int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = a->arr[l + i];
    for (int i = 0; i < n2; i++) R[i] = a->arr[m + 1 + i];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        a->comparisons++;
        if (L[i] <= R[j]) a->arr[k++] = L[i++];
        else a->arr[k++] = R[j++];
    }
    while (i < n1) a->arr[k++] = L[i++];
    while (j < n2) a->arr[k++] = R[j++];
}

void mergeSort(Array *a, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main() {
    int n, choice;
    printf("Enter array size: ");
    scanf("%d", &n);
    Array a;
    initArray(&a, n);
    printf("Original array: ");
    printArray(&a);
    printf("Choose sorting algorithm (1: Bubble, 2: Selection, 3: Insertion, 4: Merge): ");
    scanf("%d", &choice);
    switch (choice) {
        case 1: bubbleSort(&a); break;
        case 2: selectionSort(&a); break;
        case 3: insertionSort(&a); break;
        case 4: mergeSort(&a, 0, a.size - 1); break;
        default: printf("Invalid choice\n"); return 1;
    }
    printf("Sorted array: ");
    printArray(&a);
    printf("Comparisons: %ld\nSwaps: %ld\n", a.comparisons, a.swaps);
    free(a.arr);
    return 0;
}