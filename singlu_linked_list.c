#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to traverse and print the elements of the singly linked list
void traverseLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Create a simple singly linked list with three nodes
    struct Node* head = createNode(1);
    struct Node* second = createNode(2);
    struct Node* third = createNode(3);

    // Connect the nodes to form the linked list
    head->next = second;
    second->next = third;

    // Print the linked list
    printf("Linked List: ");
    traverseLinkedList(head);

    // Don't forget to free the memory when you're done
    free(head);
    free(second);
    free(third);

    return 0;
}