/*

To implement a doubly linked list using arrays in C, we'll simulate the doubly linked list behavior by utilizing two arrays:

One array will store the data of the nodes.
The second array will store the next and previous indices, which simulate the links between nodes in a doubly linked list.

*/


#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Maximum size of the linked list

// Structure to represent the doubly linked list
struct DoublyLinkedList {
    int data[MAX_SIZE];    // Array to store data
    int next[MAX_SIZE];    // Array to store next pointers (indices)
    int prev[MAX_SIZE];    // Array to store previous pointers (indices)
    int head;              // Head index of the doubly linked list
    int free;              // Index of the first free position in the array
};

// Function to initialize the doubly linked list
void initList(struct DoublyLinkedList* list) {
    list->head = -1;  // Initially, the list is empty (no head)
    list->free = 0;   // First free index is 0
    
    // Initialize next[] and prev[] array for free list (all elements point to the next one)
    for (int i = 0; i < MAX_SIZE - 1; i++) {
        list->next[i] = i + 1;
        list->prev[i] = -1;
    }
    list->next[MAX_SIZE - 1] = -1;  // The last element points to -1 (no more free nodes)
    list->prev[MAX_SIZE - 1] = -1;  // Last element's previous pointer is also NULL
}

// Function to create a new node with given value
int createNode(struct DoublyLinkedList* list, int value) {
    if (list->free == -1) {
        printf("List is full\n");
        return -1; // No free space available
    }

    int newNode = list->free; // Get the first free index
    list->free = list->next[newNode];  // Update the free list to the next free index

    list->data[newNode] = value; // Set the data for the new node
    list->next[newNode] = -1;    // Set next to -1 (end of the list)
    list->prev[newNode] = -1;    // Set prev to -1 (no previous node)

    return newNode;
}

// Function to insert a node at the end of the doubly linked list
void insertNode(struct DoublyLinkedList* list, int value) {
    int newNode = createNode(list, value); // Create a new node

    if (newNode == -1) {
        return; // No space for a new node
    }

    // If the list is empty, the new node becomes the head
    if (list->head == -1) {
        list->head = newNode;
        return;
    }

    // Traverse to the last node
    int temp = list->head;
    while (list->next[temp] != -1) {
        temp = list->next[temp];
    }

    // Link the new node to the last node
    list->next[temp] = newNode;
    list->prev[newNode] = temp; // Set the previous pointer of the new node to the last node
}

// Function to delete a node with a given value
void deleteNode(struct DoublyLinkedList* list, int value) {
    int temp = list->head;

    // Traverse the list to find the node
    while (temp != -1 && list->data[temp] != value) {
        temp = list->next[temp];
    }

    // If the node is not found
    if (temp == -1) {
        printf("Value %d not found in the list\n", value);
        return;
    }

    // If the node to delete is the head
    if (temp == list->head) {
        list->head = list->next[temp];  // Move head to the next node
        if (list->head != -1) {
            list->prev[list->head] = -1; // Set the previous pointer of the new head to NULL
        }
    } else {
        list->next[list->prev[temp]] = list->next[temp];  // Bypass the node from the previous node
    }

    if (list->next[temp] != -1) {
        list->prev[list->next[temp]] = list->prev[temp];  // Bypass the node from the next node
    }

    // Add the node back to the free list
    list->next[temp] = list->free;
    list->prev[temp] = -1;
    list->free = temp;
}

// Function to display the doubly linked list
void displayList(struct DoublyLinkedList* list) {
    int temp = list->head;

    if (temp == -1) {
        printf("The list is empty.\n");
        return;
    }

    printf("Doubly Linked List: ");
    while (temp != -1) {
        printf("%d   ", list->data[temp]);
        temp = list->next[temp];
    }
    printf("NULL\n");
}

// Function to display the list in reverse order
void displayListReverse(struct DoublyLinkedList* list) {
    int temp = list->head;
    
    if (temp == -1) {
        printf("The list is empty.\n");
        return;
    }

    // Traverse to the last node
    while (list->next[temp] != -1) {
        temp = list->next[temp];
    }

    // Traverse the list in reverse
    printf("Doubly Linked List (Reverse): ");
    while (temp != -1) {
        printf("%d   ", list->data[temp]);
        temp = list->prev[temp];
    }
    printf("NULL\n");
}

int main() {
    struct DoublyLinkedList list;
    initList(&list);  // Initialize the doubly linked list

    // Insert elements into the list
    insertNode(&list, 10);
    insertNode(&list, 20);
    insertNode(&list, 30);
    insertNode(&list, 40);

    // Display the list in normal order
    displayList(&list);

    // Display the list in reverse order
    displayListReverse(&list);

    // Delete a node from the list
    deleteNode(&list, 20);
    displayList(&list);
    displayListReverse(&list);

    // Delete another node
    deleteNode(&list, 10);
    displayList(&list);
    displayListReverse(&list);

    // Attempt to delete a non-existing node
    deleteNode(&list, 100);
    
    return 0;
}
