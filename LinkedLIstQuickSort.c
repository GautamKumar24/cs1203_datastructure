#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

struct node{
    int val;
    struct node * next;
};
typedef struct node *  NewNode;

//Code for searching the last node in a linked list//
NewNode lastnode(NewNode head){
    NewNode temp = head;
    while (temp != NULL && temp->next != NULL){
        temp = temp->next;
    }
    return temp;
}

// The below code places the pivot node to it's sorting position//

NewNode Partition(NewNode first, NewNode last){
    NewNode pivot = first;
    NewNode front = first;
    int temp = 0;
    while(front !=NULL && front != last){
        if (front->val <last->val){
            pivot = first; 
        //Swap code if a value smaller than the pivot is found//
        
            temp= first->val;
            first->val = front->val;
            front->val = temp;
            
            first = first->next;

        }
        front = front->next; // traversing in the linked list//
    }
    temp = first->val;
    first->val = last->val;
    last->val = temp;
    return pivot;
}
// code for sorting the linked list using the quicksort technique//
NewNode LinkedListQuickSort(NewNode first, NewNode last){
    if (first ==last){
        return;
    }
    
    NewNode pivot = Partition(first, last);
    if (pivot != NULL && pivot->next != NULL){
        LinkedListQuickSort(pivot->next, last);
    }
    if (pivot != NULL && first != pivot){
        LinkedListQuickSort(first, pivot); 
    }
    } 
NewNode LinkedListPrint(NewNode head){
    if (head==NULL){
        printf("List is empty");
        return;
    }
    NewNode temp = head;
    
    while (temp != NULL){
        printf(" %d", temp->val);
        temp = temp->next;
    }
}

NewNode Insert(struct node** head, int value){
    struct node* Node  = (struct node* )malloc(sizeof(struct node));
    if (Node ==NULL){
        printf("Memory overflow\n");

    }
    else{
        Node->val = value;
        Node->next = NULL;
        if (*head ==NULL){
            *head = Node;

        }
        else{
            struct node* temp = *head;
            while (temp->next !=NULL){temp = temp->next;}
            temp->next = Node;
        }
    }
}
int main(){
    NewNode head = NULL;
    Insert (&head, 88); 
    Insert (&head, 99); 
    Insert (&head, 62); 
    
    
    LinkedListPrint(head);

    LinkedListQuickSort(head, lastnode(head));
    printf("\n QuickSort done on linked list:  ");
    LinkedListPrint(head);
    return 0;
    
}

//This code is inspired by: https://www.geeksforgeeks.org/quicksort-on-singly-linked-list/ 




