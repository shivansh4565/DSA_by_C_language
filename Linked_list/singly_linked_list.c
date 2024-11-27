/*
In C, a singly linked list can be implemented using arrays to simulate the behavior of linked list nodes. Each node in a singly linked list typically contains two parts:

Data: The actual data stored in the node.
Next: A pointer/reference to the next node in the list.
To simulate a singly linked list using arrays, we can use two arrays:

One for storing the data.
Another for storing the "next" index, simulating the link between nodes.

*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Maximum size of the linked list

// Structure to represent the linked list
struct SinglyLinkedList {
    int data[MAX_SIZE];   // Array to store data
    int next[MAX_SIZE];    // Array to store the next index (links)
    int head;              // Head index of the linked list
    int free;              // Index of the first free position in the array
};

// Initialize the linked list
void initList(struct SinglyLinkedList* list) {
    list->head = -1;  // Initially, the list is empty (no head)
    list->free = 0;   // First free index is 0
    
    // Initialize next[] array for free list (all elements point to the next one)
    for (int i = 0; i < MAX_SIZE - 1; i++) {
        list->next[i] = i + 1;
    }
    list->next[MAX_SIZE - 1] = -1;  // The last element points to -1 (no more free nodes)
}

// Function to add a new node at the end of the linked list
void insertNode(struct SinglyLinkedList* list, int value) {
    if (list->free == -1) {
        printf("List is full\n");
        return;
    }
    
    int newNode = list->free;  // Get the first free index
    list->free = list->next[newNode];  // Update the free list to the next free index
    
    list->data[newNode] = value;  // Set the data for the new node
    list->next[newNode] = -1;     // The next node is NULL (end of the list)

    if (list->head == -1) {
        list->head = newNode;  // If the list is empty, make the new node the head
    } else {
        // Traverse to the last node and link it to the new node
        int temp = list->head;
        while (list->next[temp] != -1) {
            temp = list->next[temp];
        }
        list->next[temp] = newNode;
    }
}

// Function to delete a node with a given value
void deleteNode(struct SinglyLinkedList* list, int value) {
    int current = list->head;
    int previous = -1;
    
    // Traverse the list to find the node
    while (current != -1 && list->data[current] != value) {
        previous = current;
        current = list->next[current];
    }
    
    // If the node is not found
    if (current == -1) {
        printf("Value %d not found in the list\n", value);
        return;
    }
    
    // Remove the node from the list
    if (previous == -1) {
        list->head = list->next[current];  // If the node to delete is the head
    } else {
        list->next[previous] = list->next[current];  // Bypass the current node
    }
    
    // Add the current node back to the free list
    list->next[current] = list->free;
    list->free = current;
}

// Function to display the linked list
void displayList(struct SinglyLinkedList* list) {
    int temp = list->head;
    
    if (temp == -1) {
        printf("List is empty\n");
        return;
    }
    
    printf("Linked List: ");
    while (temp != -1) {
        printf("%d -> ", list->data[temp]);
        temp = list->next[temp];
    }
    printf("NULL\n");
}

int main() {
    struct SinglyLinkedList list;
    initList(&list);  // Initialize the linked list
    
    // Insert elements into the list
    insertNode(&list, 10);
    insertNode(&list, 20);
    insertNode(&list, 30);
    insertNode(&list, 40);
    
    // Display the list
    displayList(&list);
    
    // Delete an element from the list
    deleteNode(&list, 20);
    displayList(&list);
    
    // Delete another element from the list
    deleteNode(&list, 10);
    displayList(&list);
    
    // Attempt to delete a non-existing element
    deleteNode(&list, 100);
    
    return 0;
}
