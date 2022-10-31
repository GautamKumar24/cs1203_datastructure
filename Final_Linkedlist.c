#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data; 
    struct Node* next;

};

//code for inserting data in a linked list

void insert(struct Node** head, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head);
    (*head) = new_node;
}

//print linked list
void linkedlist(struct Node* head)
{
    struct Node* temp = head;
    while (temp != NULL){
        printf("%d-> ", temp->data);
        temp = temp->next;

    }
}

int main()
{
    struct Node* head = NULL;
    insert(&head, 45);
    insert(&head, 43);
    insert(&head, 28);      //we can keep on adding data in the given linked list
    insert(&head, 48);

    printf("Given linked lists \n");
    linkedlist(head); 
}


// Working of the code
// empty nodes in the beginning of the linked lists
//int main(){}
// struct Node* Box = NULL;
// struct Node* Box1 = NULL;
// .......
// struct Node* Box_n = NULL;

    

// allocating the memory address of the lists
// Box = (struct Node*)malloc(sizeof(struct Node));
// Box = (struct Node*)malloc(sizeof(struct Node));
// .......
// Box_n = (struct Node*)malloc(sizeof(struct Node));



//Now, the pointer has been created we would assign value, let the integer 10 be in the first node
// Box->data = 10;
// Box->next = Box1; //stores the address of the second node

// keeping the data in the second node and saving the address of the third node which is linking second and third node
//Box1->data = 30;
//Box1->next = Box2

//similarly assigning the data and the address of the next node 
// Box_n-1 ->data = x;(say)
// Box_n-1 ->data = Box_n
