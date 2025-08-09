How can we implement the doubly linked list using structure? Write a method to insert(after
given node) and delete the node in doubly linked list. Write main() to demonstrate the use
of the functions.

## Data Structure Definition

The program implements a doubly linked list using a Node structure in C. Each node contains an integer data field to store the value, and two pointers: prev to point to the previous node and next to point to the next node. Both pointers are set to NULL for an isolated node, enabling bidirectional traversal and flexible manipulation of the list, with the head pointer marking the start of the list.

## Function Descriptions

The program provides functions to manage and manipulate the doubly linked list. The createNode function allocates memory for a new node, sets its data to the provided integer, initializes prev and next pointers to NULL, and returns the node, serving as the foundation for list construction. The insertAfter function inserts a new node with given data after a specified node: it creates a new node, links its next to the previous node’s next, sets its prev to the previous node, updates the prev pointer of the next node (if it exists), and links the previous node’s next to the new node, seamlessly integrating it into the list. The deleteNode function removes a specified node from the list: it checks if the list or node is valid, updates the head if the node is the first, adjusts the prev and next pointers of adjacent nodes to bypass the deleted node, and frees its memory. The printList function traverses the list from the head, printing each node’s data followed by a space, and ends with a newline, providing a clear view of the list’s contents.

## Main Function Overview

The main function demonstrates the insertion and deletion operations. It creates a head node with data 1, inserts a node with data 2 after the head, and inserts a node with data 3 after the second node, forming the list 1<->2<->3. It prints the list, deletes the node with data 2 (the second node), and prints the updated list (1<->3). The function returns 0 to indicate successful execution.

## Sample Output

When the program runs, it produces the following output:
<br>
```
List: 1 2 3
After deleting node with data 2: 1 3
```

This output shows the initial list with three nodes and the updated list after removing the node with data 2, confirming correct insertion and deletion operations.
