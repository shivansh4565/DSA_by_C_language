/*

A Circular Linked List is a type of linked list where the last node points back to the first node instead of NULL. This creates a circular structure. You can implement a Circular Linked List using arrays by simulating the concept of linked list nodes, where each node in the list has:

Data: Stores the actual data of the node.
Next: Points to the index of the next node in the array.
In this array-based implementation, we'll maintain an array to store the data and another array to simulate the next pointer (which stores the index of the next node). The array-based circular linked list is particularly useful for simulating how memory is managed in real-world linked lists.
*/


#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Maximum number of nodes in the list

// Structure to represent the circular linked list
struct CircularLinkedList {
    int data[MAX_SIZE]; // Array to store data of nodes
    int next[MAX_SIZE]; // Array to store the indices of the next nodes
    int head;           // Index of the first node (head)
    int free;           // Index of the first free node
};

// Function to initialize the circular linked list
void initList(struct CircularLinkedList* list) {
    list->head = -1;  // Initially, the list is empty (no head)
    list->free = 0;   // The first free node is at index 0
    
    // Initialize the next[] array to simulate free list
    for (int i = 0; i < MAX_SIZE - 1; i++) {
        list->next[i] = i + 1;
    }
    list->next[MAX_SIZE - 1] = -1;  // The last element points to -1 (no free node)
}

// Function to create a new node with a given value
int createNode(struct CircularLinkedList* list, int value) {
    if (list->free == -1) {
        printf("List is full\n");
        return -1; // No free space available
    }

    int newNode = list->free; // Get the first free index
    list->free = list->next[newNode];  // Update the free list

    list->data[newNode] = value; // Set the data for the new node
    list->next[newNode] = -1;    // Initialize the next pointer to -1 (will be updated later)

    return newNode;
}

// Function to insert a node at the end of the circular linked list
void insertNode(struct CircularLinkedList* list, int value) {
    int newNode = createNode(list, value); // Create a new node
    
    if (newNode == -1) {
        return; // No space for a new node
    }

    // If the list is empty, make the new node the head and set the next pointer to itself
    if (list->head == -1) {
        list->head = newNode;
        list->next[newNode] = newNode; // Point to itself, circular link
        return;
    }

    // Traverse to the last node
    int temp = list->head;
    while (list->next[temp] != list->head) {
        temp = list->next[temp];
    }

    // Link the last node to the new node
    list->next[temp] = newNode;
    list->next[newNode] = list->head; // Set the new node's next pointer to the head
}

// Function to delete a node with a given value from the circular linked list
void deleteNode(struct CircularLinkedList* list, int value) {
    if (list->head == -1) {
        printf("List is empty\n");
        return;
    }

    int temp = list->head;
    int prev = -1;

    // Search for the node to delete
    do {
        if (list->data[temp] == value) {
            break;
        }
        prev = temp;
        temp = list->next[temp];
    } while (temp != list->head);

    // If the node is not found
    if (temp == list->head && list->data[temp] != value) {
        printf("Value %d not found in the list\n", value);
        return;
    }

    // If the node to delete is the head
    if (temp == list->head) {
        // If it's the only node in the list
        if (list->next[temp] == list->head) {
            list->head = -1; // List becomes empty
        } else {
            // Move the head to the next node
            list->head = list->next[temp];
        }
    } else {
        // Bypass the node to be deleted
        list->next[prev] = list->next[temp];
    }

    // Add the node back to the free list
    list->next[temp] = list->free;
    list->free = temp;
}

// Function to display the circular linked list
void displayList(struct CircularLinkedList* list) {
    if (list->head == -1) {
        printf("The list is empty.\n");
        return;
    }

    int temp = list->head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", list->data[temp]);
        temp = list->next[temp];
    } while (temp != list->head);
    printf("(back to head)\n");
}

int main() {
    struct CircularLinkedList list;
    initList(&list);  // Initialize the circular linked list

    // Insert elements into the list
    insertNode(&list, 10);
    insertNode(&list, 20);
    insertNode(&list, 30);
    insertNode(&list, 40);

    // Display the list
    displayList(&list);

    // Delete a node from the list
    deleteNode(&list, 20);
    displayList(&list);

    // Delete the head node
    deleteNode(&list, 10);
    displayList(&list);

    // Delete a non-existing node
    deleteNode(&list, 100);
    
    return 0;
}
