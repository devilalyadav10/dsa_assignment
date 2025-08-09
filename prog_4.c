#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void insertAfter(Node *prevNode, int data) {
    if (prevNode == NULL) return;
    Node *newNode = createNode(data);
    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    if (prevNode->next) prevNode->next->prev = newNode;
    prevNode->next = newNode;
}

void deleteNode(Node **head, Node *delNode) {
    if (*head == NULL || delNode == NULL) return;
    if (*head == delNode) *head = delNode->next;
    if (delNode->next) delNode->next->prev = delNode->prev;
    if (delNode->prev) delNode->prev->next = delNode->next;
    free(delNode);
}

void printList(Node *head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node *head = createNode(1);
    insertAfter(head, 2);
    insertAfter(head->next, 3);
    printf("List: ");
    printList(head);
    deleteNode(&head, head->next);
    printf("After deleting node with data 2: ");
    printList(head);
    return 0;
}