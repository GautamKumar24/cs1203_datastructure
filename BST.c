//In order traversal in Binary Search Tree 

#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *lchild, *rchild;
};

// Code to create a node

struct node *newnode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->value = data;
    temp->lchild = temp->rchild = NULL;
    return temp;
}



// Code to insert a node in the bst tree
struct node *insert(struct node *node, int value)
{
    if (node == NULL)
        return newnode(value); // The case when the tree is empty

    if (value < node->value)
        node->lchild = insert(node->lchild, value);  //creating a left child of bst

    else
        node->rchild = insert(node->rchild, value); //creating a right child of bst

    return node;


}

void Inorder(struct node *parent){
    if (parent != NULL){
        Inorder(parent->lchild);
        printf("%d -> ", parent->value);

    
        Inorder(parent->rchild);
    }
}





int main(){
    struct node *parent = NULL;
    parent = insert(parent, 15);
    parent = insert(parent, 17);
    parent = insert(parent, 12);
    parent = insert(parent, 61);
    parent = insert(parent, 75);
    parent = insert(parent, 18);
    parent = insert(parent, 19);
    parent = insert(parent, 41);

    printf("Inorder traversal of Binary Search Tree: ");
    Inorder(parent); 


}


// Work Cited:  https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/ 