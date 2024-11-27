/*

To implement a Doubly Linked List using pointers in C, each node contains:

Data: The actual data stored in the node.
Next: A pointer to the next node in the list.
Prev: A pointer to the previous node in the list.
We will use dynamic memory allocation to create each node and maintain two pointers, next and prev, for the doubly linked list's forward and backward traversal.

Key Points:
Each node points to the next node and the previous node in the list.
The head of the list points to the first node, and the tail (last node) points to NULL.
*/


#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the doubly linked list
struct Node {
    int data;          // Data part of the node
    struct Node* next; // Pointer to the next node
    struct Node* prev; // Pointer to the previous node
};

// Function to create a new node with a given value
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for new node
    newNode->data = value; // Set the data of the new node
    newNode->next = NULL;   // Set the next pointer to NULL (this will be updated later)
    newNode->prev = NULL;   // Set the prev pointer to NULL (this will be updated later)
    return newNode;
}

// Function to insert a node at the end of the doubly linked list
void insertNode(struct Node** head, int value) {
    struct Node* newNode = createNode(value); // Create a new node

    if (*head == NULL) { // If the list is empty
        *head = newNode;  // New node becomes the head of the list
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) { // Traverse to the last node
        temp = temp->next;
    }

    temp->next = newNode;  // Link the last node to the new node
    newNode->prev = temp;  // Set the previous pointer of the new node to the last node
}

// Function to delete a node with a given value from the doubly linked list
void deleteNode(struct Node** head, int value) {
    struct Node* temp = *head;

    // Search for the node with the given value
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    // If the node is not found
    if (temp == NULL) {
        printf("Value %d not found in the list\n", value);
        return;
    }

    // If the node to be deleted is the head
    if (temp == *head) {
        *head = temp->next;  // Move the head to the next node
        if (*head != NULL) {
            (*head)->prev = NULL; // Set the previous pointer of the new head to NULL
        }
    } else {
        // Bypass the node to be deleted
        temp->prev->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
    }

    free(temp); // Free the memory of the deleted node
}

// Function to display the list from head to tail
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to display the list from tail to head (reverse traversal)
void displayListReverse(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    // Traverse to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("Doubly Linked List (Reverse): ");
    while (temp != NULL) {
        printf("%d   ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL; // Start with an empty list

    // Insert nodes into the list
    insertNode(&head, 10);
    insertNode(&head, 20);
    insertNode(&head, 30);
    insertNode(&head, 40);

    // Display the list in forward order
    displayList(head);

    // Display the list in reverse order
    displayListReverse(head);

    // Delete a node from the list
    deleteNode(&head, 20);
    displayList(head);
    displayListReverse(head);

    // Delete another node
    deleteNode(&head, 10);
    displayList(head);
    displayListReverse(head);

    // Attempt to delete a non-existing node
    deleteNode(&head, 100);

    return 0;
}
