#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
}



struct Node* delete(struct Node* last) {
    if (last == NULL) {
        // If the list is empty
        printf("List is empty\n");
        return NULL;
    }

    struct Node* head = last->next;

    if (head == last) {
        // If there is only one node in the list
        free(head);
        last = NULL;
    } else {
        // More than one node in the list
        last->next = head->next;
        free(head);
    }

    return last;
}


void printList(struct Node *last)
{
    if (last == NULL) return;

    struct Node *head = last->next;
    while (1){
        printf("%d ", head->data);
        head = head->next;
        if (head == last->next)
            break;
    }
    printf("\n");
}

// Function to delete a specific node in the circular linked list
struct Node* deleteSpecificNode(struct Node* last, int key) {
    if (last == NULL) {
        // If the list is empty
        printf("List is empty, nothing to delete.\n");
        return NULL;
    }

    struct Node* curr = last->next;
    struct Node* prev = last;

    // If the node to be deleted is the only node in the list
    if (curr == last && curr->data == key) {
        free(curr);
        last = NULL;
        return last;
    }

    // If the node to be deleted is the first node
    if (curr->data == key) {
        last->next = curr->next;
        free(curr);
        return last;
    }

    // Traverse the list to find the node to be deleted
    while (curr != last && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    // If the node to be deleted is found
    if (curr->data == key) {
        prev->next = curr->next;
        if (curr == last) {
            last = prev;
        }
        free(curr);
    } else {
        // If the node to be deleted is not found
        printf("Node with data %d not found.\n", key);
    }

    return last;
}

int main()
{
    // Create circular linked list: 2, 3, 4
    struct Node *first = createNode(0);
    first->next = createNode(1);
    first->next->next = createNode(4);
    struct Node *last = first->next->next;
    last->next = first;

    printf("Original list: ");
    printList(last);

    // Insert 5 at the beginning
    last = delete(last);
 last = delete(last);
    printf("List after inserting at the end: ");
    printList(last);

    // Delete a specific node
    int key = 3;
    last = deleteSpecificNode(last, key);
  printList(last);
    return 0;
}