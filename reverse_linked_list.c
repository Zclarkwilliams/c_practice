/*
*   Reversing a linked list
*   Recursive and Iterative method
*   Author: Zachary Clark-Williams
*   date last revised: 09/08/18
*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* ReverseList(struct Node* head){

    struct Node *prev, *next, *curr;
    curr = head;
    prev = NULL;

    while(curr != NULL){
        next = curr->next;  // move pointer next to next node in list
        curr->next = prev;  // link pointer next to the previous node
        prev = curr;        // set what was previous to what is current
        curr = next;        // move to the next node to be pointing to the previous
    }
    head = prev;            // set head pointer to the last node in list
    return head;            // return the point to the last node
};

/*  PUSH the data to the front of the linked list   */
struct Node* PushData(struct Node** head, int data){
    // allocate the memory for the new node of the list
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    // enter the data passed in
    new_node->data = data;
    
    // store the pointer to the new node as pointer next of current struct
    new_node->next = (*head);
    
    // move the head to point to the new node
    (*head) = new_node;

    return (*head);
};

/*  add the data to a new node after a given reference node of the linked list   */
struct Node* MidData(struct Node* prev_node, int data){
    // check to see of the 'prev_node' is valid (!NULL)
    if (prev_node == NULL){
        printf("ERROR: the given predicessing node cannot be NULL.");
        exit; // remove self from invalid situation
    }
    
    // allocate memory for the new node
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    // enter the data passed in
    new_node->data = data;

    // set the pointer next to the next node and previous to new_node
    new_node->next = prev_node->next; 
    prev_node->next = new_node;
};

/*  Append the linked list with a new node of data  */
struct Node* AppendData(struct Node** head, int data){
    // allocate the memory for the new node and data
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    // enter the data into the the new_node to be appended
    new_node->data = data;

    // new_node is now end so pointer next is to NULL
    new_node->next = NULL;

    // Test the 'end_node' to see if empty so end node = top node
    if (head == NULL){
        *head = new_node; // head is now new_node appended
    }

    // traverse list till reached end of list to append at
    struct Node* last = *head;
    while(last->next != NULL){
        last = last->next;
    }

    // alter the previous end node to point pointer next to new_node
    last->next = new_node;

    return (*head);
};

// print a list of data stored as int 'data'
void PrintList(struct Node* head){
    if(head != NULL)
    {
        printf("%d\t", head->data);
        //head = head->next;    //iterative printing function form
        PrintList(head->next);  // recursive printing form
    }
}

// print a linked list in reverse order from how it is passed by reference
void PrintReverse(struct Node* head){
    if (head == NULL){
        return;
    }
    PrintReverse(head->next);
    printf("%d\t", head->data);
}

int main(int argc, char **argv){
    // generate the head of the list as NULL
    struct Node* head = NULL;

    head = PushData(&head, 2);
    head = PushData(&head, 27);
    head = PushData(&head, 8);
    head = PushData(&head, 30);
    head = PushData(&head, 43);
    PrintList(head);
    printf("\r\n");
    PrintReverse(head);
    printf("\r\n");
    head = ReverseList(head);
    PrintList(head);

    return 0;
}