# Min and Max Heap Documentation

## Data Structure Definition
- **Heap**: Struct with integer array `items` (size 100) and integer `size`.

## Functions Implemented
- `swap(int *a, int *b)`: Swaps two integers.
- `minHeapify(Heap *h, int i)`: Maintains min-heap property at index i.
- `maxHeapify(Heap *h, int i)`: Maintains max-heap property at index i.
- `buildMinHeap(Heap *h)`: Builds a min-heap from the array.
- `buildMaxHeap(Heap *h)`: Builds a max-heap from the array.
- `printHeap(Heap *h)`: Prints the heap.

## Main Method Organization
- Initializes array `{4, 10, 3, 5, 1}`.
- Builds and prints min-heap.
- Reinitializes array and builds/prints max-heap.

## Sample Output
```
Original array: 4 10 3 5 1
Min Heap: 1 4 3 5 10
Max Heap: 10 5 3 4 1
```