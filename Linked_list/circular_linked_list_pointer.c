/*
o implement a Circular Linked List using pointers in C, each node in the list contains:

Data: The actual data stored in the node.
Next: A pointer that points to the next node in the list.
In a circular linked list, the last node's next pointer points to the first node, forming a circle. This circular structure allows us to traverse the list starting from any node and continue indefinitely.

*/
#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the circular linked list
struct Node {
    int data;          // Data part of the node
    struct Node* next; // Pointer to the next node
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for the new node
    newNode->data = value;  // Set the node's data
    newNode->next = newNode; // Initially, point next to itself (circular)
    return newNode;
}

// Function to insert a node at the end of the circular linked list
void insertNode(struct Node** head, int value) {
    struct Node* newNode = createNode(value); // Create a new node
    if (*head == NULL) {
        *head = newNode; // If the list is empty, set the new node as the head
    } else {
        struct Node* temp = *head;
        // Traverse to the last node (the node whose next points to the head)
        while (temp->next != *head) {
            temp = temp->next;
        }
        // Link the last node to the new node and set the new node's next pointer to the head
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Function to delete a node with a given value
void deleteNode(struct Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    // Check if the node to delete is the head node
    if (temp->data == value) {
        // If there is only one node in the list
        if (temp->next == *head) {
            free(temp);
            *head = NULL;
            return;
        }
        // If there are multiple nodes, find the last node to update its next pointer
        while (temp->next != *head) {
            temp = temp->next;
        }
        // Update the last node's next pointer to point to the new head
        temp->next = (*head)->next;
        free(*head);
        *head = (*head)->next;
        return;
    }

    // Traverse the list to find the node to delete
    while (temp->next != *head && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // If node is not found
    if (temp->data != value) {
        printf("Node with value %d not found\n", value);
        return;
    }

    // Node to delete is not the head, so update the previous node's next pointer
    prev->next = temp->next;
    free(temp);
}

// Function to display the list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

int main() {
    struct Node* head = NULL; // Start with an empty list

    // Insert nodes into the circular linked list
    insertNode(&head, 10);
    insertNode(&head, 20);
    insertNode(&head, 30);
    insertNode(&head, 40);

    // Display the circular linked list
    displayList(head);

    // Delete a node
    deleteNode(&head, 20);
    displayList(head);

    // Delete the head node
    deleteNode(&head, 10);
    displayList(head);

    // Attempt to delete a non-existing node
    deleteNode(&head, 100);

    return 0;
}

