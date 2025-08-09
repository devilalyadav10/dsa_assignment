# Linked List Reverse Traversal Documentation

## Data Structure Definition
- **Node**: Struct with integer `data` and pointer `next` to the next node.

## Functions Implemented
- `createNode(int data)`: Creates a new node with given data.
- `insertEnd(Node **head, int data)`: Inserts a node at the end of the list.
- `reverseTraversal(Node *head)`: Recursively traverses the list in reverse order.

## Main Method Organization
- Creates a linked list with values 1, 2, 3.
- Calls `reverseTraversal` to print the list in reverse.
- Prints newline after traversal.

## Sample Output
```
Reverse Traversal: 3 2 1
```