Write and Implement the reverse traversal algorithm in the the linked list. Write main() to
demonstrate the use of the function.

## Data Structure Definition

The program uses a singly linked list to store and traverse integers in reverse order. The linked list is defined by a `Node` structure, which contains an integer `data` field to hold the value and a pointer `next` to the next node in the list. The `next` pointer is set to `NULL` for the last node, forming a chain of nodes that starts from a head pointer, enabling dynamic memory allocation and flexible list manipulation.
<br>
## Function Descriptions

The program implements three key functions to manage and traverse the linked list. The `createNode` function allocates memory for a new node, initializes its `data` field with a given integer, sets its `next` pointer to `NULL`, and returns the node, providing a building block for the list. The `insertEnd` function adds a new node with specified data to the end of the list: if the list is empty (head is `NULL`), it sets the head to the new node; otherwise, it traverses to the last node and links the new node to it, ensuring the list grows efficiently. The `reverseTraversal` function performs a recursive reverse traversal of the linked list: it takes a head pointer, recursively calls itself on the next node until it reaches `NULL`, then prints the current node’s data as it unwinds, resulting in the list’s elements being displayed in reverse order.
<br>
## Main Function Overview

The `main` function demonstrates the reverse traversal algorithm. It initializes an empty linked list with a `NULL` head pointer. It then calls `insertEnd` three times to add nodes with data values 1, 2, and 3, forming the list 1->2->3. The program prints "Reverse Traversal: ", calls `reverseTraversal` on the head to print the list’s elements in reverse order (3, 2, 1), and adds a newline for clarity. Finally, it returns 0 to indicate successful execution.
<br>
## Sample Output

When the program runs, it produces the following output:
<br>
```
Reverse Traversal: 3 2 1
```

This output shows the linked list’s elements printed in reverse order, confirming that the recursive traversal correctly processes the list 1->2->3 to output 3, 2, 1.
