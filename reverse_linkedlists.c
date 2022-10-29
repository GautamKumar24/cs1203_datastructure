
// Iterative method to reverse a given linked lists
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
// Reversing the linked list
static void reverse(Struct Node** head){
    struct node* prevpontr = Null;
    struct node* currentpontr = head;
    struct node* nextpontr;
    while (currentpontr != Null){
        nextpontr = currentpontr->next; //Iteratively moves to each node
        current->next = prevpontr; //changing the pointer of the node
        
        //Move the pointer ahead by one postition
        prevpontr = currentpontr;
        currentpontr = nextpontr;


    }
    *head = prevpontr;
}

void push(struct Node** head, int new_data)
{
    struct Node* new_node
        = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head);
    (*head) = new_node;
    }

// print linked list
void printlist(struct Node* head)
{
    struct Node* temp = head;
    while (temp != Null){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
 struct Node* head = Null;
push(&head, 56);
push(&head, 08);
push(&head, 02);
push(&head, 99);

printf("Given linked lists\n");
printlist(head);
reverse(head);
printf("\n"Reversed linked list \n");
printlist(head);
getchar();   
}

