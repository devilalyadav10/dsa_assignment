#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) *head = newNode;
    else {
        Node *temp = *head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

void reverseTraversal(Node *head) {
    if (head == NULL) return;
    reverseTraversal(head->next);
    printf("%d ", head->data);
}

int main() {
    Node *head = NULL;
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    printf("Reverse Traversal: ");
    reverseTraversal(head);
    printf("\n");
    return 0;
}