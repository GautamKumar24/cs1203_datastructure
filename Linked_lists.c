#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;      #initializing the pointer, it stores the address of node type variable
}

// empty nodes in the beginning of the linked lists
int main() {
    struct Node* Box = Null;
    struct Node* Box1 = Null;
    struct Node* Box2 = Null;
    struct Node* Box3 = Null;

// allocating the memory address of the lists
Box = (struct Node*)malloc(sizeof(struct Node));
Box1 = (struct Node*)malloc(sizeof(struct Node));
Box2 = (struct Node*)malloc(sizeof(struct Node));
Box3 = (struct Node*)malloc(sizeof(struct Node));

//Now, the pointer has been created we would assign value, let the integer 10 be in the first node
Box->data = 10;
Box->next = Box1; //stores the address of the second node

// keeping the data in the second node and saving the address of the third node which is linking second and third node
Box1->data = 30;
Box1->next = Box2;

//similarly assigning the data and the address of the next node 
Box2->data = 50;
Box2->next = Box3;

Box3->data = 70;
Box3->next = Null; // we aren't saving anything further so the node is empty


}

// I am unable to print the linked lists containing the data entered and the address of the corresponding nodes of the linked lists.