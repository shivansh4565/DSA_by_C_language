#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// creation of node 
typedef struct Node {
    int data;
    struct Node* next;
} Node;


 // traversal in a linked list
void traverse(Node* head) {
    Node* curr = head;  // Start from the head node
    while (curr != NULL) {  // Traverse until the end of the list
        printf("%d  ", curr->data);  // Print the data
        curr = curr->next;  // Move to the next node
    }
    }
//function to create a new node
Node* createNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;  // Set data for the new node
    temp->next = NULL;   // Set next to NULL
    return temp;         // Return the new node
}
bool search(Node *head, int target){
while (head!=NULL)
{
    if(head->data==target){
        printf("got the value");
        }

    head= head->next;
}
return false;
}

//length  of a singly ll
int length( struct Node* head) {
    int length = 0;
    struct Node* curr=head;
    while(curr!=NULL){
        length++;
        curr=curr->next;
    }
    return length;
}
// insertion at beginnning of a linked list 
struct Node* insertAtFront(struct Node* head, int value)
{  struct Node* new_node = createNode(value);
  new_node->next = head;
   return new_node;
}

// insert at end
struct Node*insertAtend(struct Node* head,int val){
    struct Node* new_node = createNode(val);
    if(head==NULL)return new_node;
    //if the list is empty
    struct Node* current = head;
     while (current->next!=NULL){
        current=current->next;
     }current->next= new_node;
     return head;
}
//insert AT a position 

struct Node* insertpos(struct Node* head, int pos, int data) {
    if (pos < 1) {
        printf("Invalid position!\n");
        return head;
    }

    // Special case for inserting at the head
    if (pos == 1) {
        struct Node* temp = createNode(data);
        temp->next = head;
        return temp;
    }

    // Traverse the list to find the node 
    // before the insertion point
    struct Node* prev = head;
    int count = 1;
    while (count < pos - 1 && prev != NULL) {
        prev = prev->next;
        count++;
    }

    // If position is greater than the number of nodes
    if (prev == NULL) {
        printf("Invalid position!\n");
        return head;
    }

    // Insert the new node at the specified position
    struct Node* temp = createNode(data);
    temp->next = prev->next;
    prev->next = temp;

    return head;
}

// Function to remove the first node of the linked list

struct Node* deleteHead(struct Node* head) {
  
    // Check if the list is empty
    if (head == NULL)
        return NULL;

    // Store the current head in a 
      // temporary variable
    struct Node* temp = head;

    // Move the head pointer to the next node
    head = head->next;

    // Free the memory of the old head node
    free(temp);

    return head;
}

int main() {
    Node* head = createNode(10);   // Create the first node
    head->next = createNode(20);    // Create the second node
    head->next->next = createNode(30); // Create the third node
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);
    printf("Linked list: ");
    traverse(head); 
     // Traverse and print the linked list
     printf("\n");
search(head,40);
 printf("\n");
    printf("Length of the linked list: %d\n", length(head));  // Output: 5
 printf("\n");
     printf("After inserting Nodes at the front:");
    head = insertAtFront(head, 100);
traverse(head);
 printf("\n");
     printf("After inserting Nodes at the end:");
    head = insertAtend(head, 200);
traverse(head);
insertpos(head,4,56);
printf("\n");
traverse(head);
 head = deleteHead(head);
    //done 
printf("\n");
traverse(head);


return 0;
}