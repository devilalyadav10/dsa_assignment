Given the array of the data (unsorted), Write a program to build the min and max heap.

## Data Structure Definition
The program uses a `Heap` structure to represent a heap, which is implemented as an array-based binary tree. The structure contains an integer array `items` of size `MAX` (100) to store the heap elements and an integer `size` to track the number of elements. This setup allows the program to manage an unsorted array and transform it into either a min-heap (where each parent is smaller than its children) or a max-heap (where each parent is larger than its children) using the array indices to represent the tree structure.

## Function Descriptions
The program includes functions to build and maintain min and max heaps. The `swap` function exchanges the values of two integers, enabling reordering during heapification. The `minHeapify` function ensures the min-heap property at a given index by comparing the node with its left and right children, identifying the smallest value, and recursively swapping and heapifying if a smaller child exists. The `maxHeapify` function similarly maintains the max-heap property by identifying the largest value among the node and its children, swapping and recursively heapifying if a larger child is found. The `buildMinHeap` function constructs a min-heap by applying `minHeapify` to all non-leaf nodes (from the last parent to the root), ensuring the smallest element is at the root. The `buildMaxHeap` function builds a max-heap by applying `maxHeapify` in the same manner, placing the largest element at the root. The `printHeap` function displays the heap’s elements in array order, followed by a newline, for easy visualization of the heap structure.

## Main Function Overview
The `main` function demonstrates the construction of min and max heaps. It initializes a `Heap` structure with an array of five unsorted integers (4, 10, 3, 5, 1) and sets the heap size to 5. It prints the original array, builds and prints a min-heap, restores the original array by copying the input values, and then builds and prints a max-heap. The function returns 0 to indicate successful execution, showcasing both heap types derived from the same input.

## Sample Output
When the program runs with the input array {4, 10, 3, 5, 1}, it produces the following output:
```
Original array: 4 10 3 5 1
Min Heap: 1 4 3 5 10
Max Heap: 10 5 3 4 1
```
This output displays the original unsorted array, followed by the min-heap (where 1 is the root, ensuring parents are smaller than children), and the max-heap (where 10 is the root, ensuring parents are larger than children), confirming correct heap construction.
