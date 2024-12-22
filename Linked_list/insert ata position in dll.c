#include <stdio.h>
#include <stdlib.h>

// Definition of the Node structure
struct Node{
    int data;
    struct Node *next;
};

// Function to search for a specific value in the circular linked list
int search(struct Node *last, int key){
    if (last == NULL){
        // If the list is empty
        return 0;
    }

    struct Node *head = last->next;
    struct Node *curr = head;

    // Traverse the list to find the key
    while (curr != last){
        if (curr->data == key){
            // Key found
            return 1;
        }
        curr = curr->next;
    }

    // Check the last node
    if (last->data == key){
        // Key found
        return 1;
    }
    // Key not found
    return 0;
}

// Function to print the circular linked list
void printList(struct Node *last){
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
// Function to create a new node
struct Node *createNode(int value){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    return temp;
}

int main(){
    // Create circular linked list: 2, 3, 4
    struct Node *first = createNode(2);
    first->next = createNode(3);
    first->next->next = createNode(4);

    struct Node *last = first->next->next;
    last->next = first;

    printf("Original list: ");
    printList(last);

    // Search for a specific value
    int key = 3;
    int found = search(last, key);
    if (found){
        printf("Value %d found in the list.\n", key);
    }
    else{
        printf("Value %d not found in the list.\n", key);
    }

    return 0;
}