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

// Function to insert a node at the beginning
// of the circular linked list
struct Node *insertAtBeginning(struct Node *last, int value)
{
    struct Node *newNode = createNode(value);

    // If the list is empty, make the new node point to itself
    // and set it as last
    if (last == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }

    // Insert the new node at the beginning
    newNode->next = last->next;
    last->next = newNode;

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
    last = insertAtBeginning(last, 1);
 last = insertAtBeginning(last, 0);
    printf("List after inserting 5 at the beginning: ");
    printList(last);

    return 0;
}