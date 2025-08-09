# Sorting Algorithms Documentation

## Data Structure Definition
- **Array**: Struct with integer array `arr`, integer `size`, and long integers `comparisons` and `swaps`.

## Functions Implemented
- `initArray(Array *a, int n)`: Initializes array with random integers [1, 1000].
- `printArray(Array *a)`: Prints the array.
- `bubbleSort(Array *a)`: Implements bubble sort with comparison/swap counting.
- `selectionSort(Array *a)`: Implements selection sort with counting.
- `insertionSort(Array *a)`: Implements insertion sort with counting.
- `merge(Array *a, int l, int m, int r)`: Merges two sorted subarrays.
- `mergeSort(Array *a, int l, int r)`: Implements merge sort recursively.

## Main Method Organization
- Takes user input for array size and sorting algorithm choice.
- Generates random array, prints it.
- Sorts using chosen algorithm, prints sorted array.
- Displays comparisons and swaps.

## Sample Output
```
Enter array size: 5
Original array: 542 123 897 321 456
Choose sorting algorithm (1: Bubble, 2: Selection, 3: Insertion, 4: Merge): 3
Sorted array: 123 321 456 542 897
Comparisons: 10
Swaps: 6
```