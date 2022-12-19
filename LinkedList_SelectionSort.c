#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct node {
    int val;
    struct node * next;

};
typedef struct node *NodeAddress;


NodeAddress SelectionSortLinkedList( NodeAddress head){
    //We need three pointers, the pointer i points to the first element in the array and the pointer j traverses the array
    // 

    NodeAddress i, minimum, j;

    i = head;

    while(i->next != NULL){
        minimum = i;
        j = i->next;


    //Finding the minimum element in the array//
        while(j != NULL){
            if (minimum->val > j->val){
                minimum = j;
            }

            j  = j->next;
        }


        //Once we get the minimum element we swap it with the first element of the array//
        int x = i->val;
        i->val = minimum->val;
        minimum->val = x;

    //Ensuring that we traverse through every node//
        i = i->next;
    }

}
   
    
// Got this entire code from the professor's lecture this remains the same as it is just generating an array and
// creating a linked list from it 
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
        head->val = a[0];
        head->next = NULL;
        temp = head;
    }
    for (i=1; i<n; i++){
        temp->next = malloc(sizeof(struct node));
    
    temp = temp->next;
    temp->val = a[i];
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
        printf(c==head?"%d":", %d", c->val);

    }
    printf(".\n");
}
//Driver's code//
int main(){
    int * a;
    int n = 10;
    NodeAddress list;
    srand (time(NULL));

    a= generateArray(n);
    list = linkedListFromAray (a, n);

    printLinkedList(list);
    SelectionSortLinkedList(list);
    printLinkedList(list);

    free (a);
    freeLinkedList(list);
    return 0; 
}


