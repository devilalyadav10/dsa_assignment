# Doubly Linked List Documentation

## Data Structure Definition
- **Node**: Struct with integer `data`, pointers `prev` and `next`.

## Functions Implemented
- `createNode(int data)`: Creates a new node.
- `insertAfter(Node *prevNode, int data)`: Inserts a new node after the given node.
- `deleteNode(Node **head, Node *delNode)`: Deletes the specified node.
- `printList(Node *head)`: Prints the list.

## Main Method Organization
- Creates a list with one node (data=1).
- Inserts nodes with data 2 and 3.
- Prints the list.
- Deletes node with data 2 and prints again.

## Sample Output
```
List: 1 2 3
After deleting node with data 2: 1 3
```