#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int value);

// Function to insert a node at a specific position in a circular linked list
struct Node* insertAtPosition(struct Node *last, int data, int pos) {
    if (last == NULL) {
        // If the list is empty
        if (pos != 1) {
            printf("Invalid position!\n");
            return last;
        }
        // Create a new node and make it point to itself
        struct Node *newNode = createNode(data);
        last = newNode;
        last->next = last;
        return last;
    }

    // Create a new node with the given data
    struct Node *newNode = createNode(data);

    // curr will point to head initially
    struct Node *curr = last->next;

    if (pos == 1) {
        // Insert at the beginning
        newNode->next = curr;
        last->next = newNode;
        return last;
    }

    // Traverse the list to find the insertion point
    for (int i = 1; i < pos - 1; ++i) {
        curr = curr->next;

        // If position is out of bounds
        if (curr == last->next) {
            printf("Invalid position!\n");
            return last;
        }
    }

    // Insert the new node at the desired position
    newNode->next = curr->next;
    curr->next = newNode;

    // Update last if the new node is inserted at the end
    if (curr == last) last = newNode;

    return last;
}

// Function to print the circular linked list
void printList(struct Node *last) {
    if (last == NULL) return;

    struct Node *head = last->next;
    while (1) {
        printf("%d ", head->data);
        head = head->next;
        if (head == last->next) break;
    }
    printf("\n");
}

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int main() {
    // Create circular linked list: 2, 3, 4
    struct Node *first = createNode(2);
    first->next = createNode(3);
    first->next->next = createNode(4);

    struct Node *last = first->next->next;
    last->next = first;

    printf("Original list: ");
    printList(last);

    // Insert elements at specific positions
    int data = 5, pos = 2;
    last = insertAtPosition(last, data, pos);
    printf("List after insertions: ");
    printList(last);

    return 0;
}