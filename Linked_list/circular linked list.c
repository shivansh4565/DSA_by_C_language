#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value);

// Function to insert a node into an empty
// circular singly linked list
struct Node* insertInEmptyList(struct Node* last, int data) {
    if (last != NULL) return last;

    // Create a new node
    struct Node* newNode = createNode(data);

    // Update last to point to the new node
    last = newNode;
    return last;
}

void printList(struct Node* last) {
    if (last == NULL) return;

    // Start from the head node
    struct Node* head = last->next;
    while (1) {
        printf("%d ", head->data);
        head = head->next;
        if (head == last->next) break;
    }
    printf("\n");
}

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = newNode;
    return newNode;
}

int main() {
    struct Node* last = NULL;

    // Insert a node into the empty list
    last = insertInEmptyList(last, 1);

    // Print the list
    printf("List after insertion: ");
    printList(last);

    return 0;
}