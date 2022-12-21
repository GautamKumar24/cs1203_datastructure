#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node{
    int data;
    struct node * next;
    

};
typedef struct node * NodeAddress; 
struct node* head = NULL; 
struct node* sorted = NULL; 

 void sortedInsert(struct node* newnode)
{
    /* Special case for the head end */
    if (sorted == NULL || sorted->data >= newnode->data) {
        newnode->next = sorted;
        sorted = newnode;
    }
    else {
        struct node* current = sorted;
        /* Locate the node before the point of insertion
         */
        while (current->next != NULL
               && current->next->data < newnode->data) {
            current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
    }
}
 
// function to sort a singly linked list
// using insertion sort
void insertionsort()
{
 
    struct node* current = head;
 
    // Traverse the given linked list and insert every
    // node to sorted
    while (current != NULL) {
 
        // Store next for next iteration
        struct node* next = current->next;
 
        // insert current in sorted linked list
        sortedInsert(current);
 
        // Update current
        current = next;
    }
    // Update head to point to sorted linked list
    head = sorted;
}


 

 // The code is taken from the notes, it creates a random linked list from an array //   
int * generateArray (int n){
    int * t = malloc(n*sizeof(int));
    if (t) {
        for(int i =0; i<n; i++){t[i]= rand()%1000;}
    }
    return t;
}

NodeAddress linkedListFromAray(int *a, int n){
    int i;
    NodeAddress head = NULL;
    NodeAddress temp = NULL;

    //special case for head
    if (n>0) {
        head = malloc(sizeof(struct node));
        head->data = a[0];
        head->next = NULL;
        temp = head;
    }
    for (i=1; i<n; i++){
        temp->next = malloc(sizeof(struct node));
    
    temp = temp->next;
    temp->data = a[i];
    temp->next = NULL;
}
return head;
}

void freeLinkedList(NodeAddress head){
    NodeAddress prev;
    while(head){
        prev = head;
        head = head->next;
        free(prev);
    }
}

void printLinkedList (NodeAddress head){
    NodeAddress c;
    printf("Linked List = ");
    for (c=head; c!=NULL; c=c->next){
        printf(c==head?"%d":", %d", c->data);

    }
    printf(".\n");
}

int main(){
    int * a;
    int n = 10;
    NodeAddress list;
    srand (time(NULL));

    a= generateArray(n);
    list = linkedListFromAray (a, n);

    printLinkedList(list);
    sortedInsert(list);
    printLinkedList(list);
     

    free (a);
    freeLinkedList(list);
    return 0; 
}
// This code is inspired by https://www.geeksforgeeks.org/insertion-sort-for-singly-linked-list/ //
