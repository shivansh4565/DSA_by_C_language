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
    return newNode;
}
struct Node *insertend(struct Node *tail, int value)
{
    struct Node *newNode = createNode(value);
    if (tail == NULL)
    {
        // If the list is empty, initialize it with the new node
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        // Insert new node after the current tail and update the tail pointer
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
    return tail;
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


int main()
{
    // Create circular linked list: 2, 3, 4
    struct Node *first = createNode(2);
    first->next = createNode(3);
    first->next->next = createNode(4);
    struct Node *last = first->next->next;
    last->next = first;

    printf("Original list: ");
    printList(last);

    // Insert 5 at the beginning
    last = insertend(last, 1);
 last = insertend(last, 0);
    printf("List after inserting 5 at the end: ");
    printList(last);

    return 0;
}