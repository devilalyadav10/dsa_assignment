Write a program that generates a list of N random integers in the range [1, 1000], where N
is provided by the user at run time. Then, perform the following tasks:
(a) Ask the user to choose a sorting algorithm from the following:
• Bubble Sort
• Selection Sort
• Insertion Sort
• Merge Sort
(b) Sort the randomly generated numbers using the chosen algorithm.
(c) Print the numbers before and after sorting.
(d) Display the total number of comparisons and swaps (if applicable) performed by the
chosen algorithm.

## Data Structure Definition
The program uses an `Array` structure to manage a dynamic array of integers for sorting. This structure includes a pointer `arr` to an array of integers, an integer `size` to store the number of elements, and two long integers, `comparisons` and `swaps`, to track the number of comparisons and swaps performed during sorting. The array is dynamically allocated based on user input, allowing flexible handling of random integers in the range [1, 1000].

## Function Descriptions
The program implements functions to generate, sort, and analyze an array using various algorithms. The `initArray` function allocates memory for the array, sets its size, initializes `comparisons` and `swaps` to 0, and fills the array with random integers from 1 to 1000 using `rand`. The `printArray` function displays the array elements in sequence, followed by a newline, for visualizing the array before and after sorting. The `bubbleSort` function sorts the array by repeatedly iterating through adjacent elements, swapping them if out of order, and incrementing `comparisons` and `swaps` as needed. The `selectionSort` function sorts by repeatedly finding the minimum element in the unsorted portion, swapping it with the first unsorted element, and tracking `comparisons` and `swaps`. The `insertionSort` function sorts by iterating through the array, inserting each element into its correct position in the sorted portion, updating `comparisons` for each check and `swaps` for each shift. The `merge` function, used by `mergeSort`, merges two sorted subarrays by comparing elements and placing them in order, incrementing `comparisons` for each comparison. The `mergeSort` function recursively divides the array into halves, sorts them, and merges them using `merge`, achieving efficient sorting without tracking swaps explicitly.

## Main Function Overview
The `main` function orchestrates the sorting process. It prompts the user for the array size, initializes an `Array` structure with random integers, and prints the original array. It then asks the user to choose a sorting algorithm (1 for Bubble, 2 for Selection, 3 for Insertion, 4 for Merge) and applies the selected algorithm using a switch statement. If an invalid choice is made, it prints an error and exits. After sorting, it prints the sorted array, the number of comparisons, and the number of swaps, then frees the allocated memory and returns 0 to indicate successful execution.

## Sample Output
When the program runs with an array size of 5 and the user selects Merge Sort (choice 4), a possible output is:
```
Enter array size: 5
Original array: 542 123 876 321 654
Choose sorting algorithm (1: Bubble, 2: Selection, 3: Insertion, 4: Merge): 4
Sorted array: 123 321 542 654 876
Comparisons: 8
Swaps: 0
```
This output shows the randomly generated array, the sorted result in ascending order, the number of comparisons made during Merge Sort, and zero swaps (as Merge Sort uses merging rather than swapping), confirming correct functionality.
