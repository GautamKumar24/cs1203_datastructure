//Code: Deletion in a Binary Search Tree 

#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *lchild, *rchild
};

//Code to create a node
struct node *newnode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->value = data;
    temp->lchild = temp->rchild = NULL;
    return temp;

}

//code for insertion in a Binary Search Tree
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

//Codes for deletion in a Binary Search Tree
struct node *Isuccessor(struct node *node){
    struct node *first = node;

    while (first && first->lchild != NULL)
    first = first->lchild;

    return first;

}

struct node *NodeDeletion(struct node *parent, int value)
{
    if (parent == NULL)
        return parent;

    if (value < parent->value)
        parent->lchild = NodeDeletion(parent->lchild, value);

    else if (value > parent->value)
        parent->rchild = NodeDeletion(parent->rchild, value);

    else
    {
        if (parent->lchild ==NULL)
        {
            struct node *temp = parent->rchild;
            free(parent);
            return temp;
        }
        else if (parent->rchild == NULL)
        {
            struct node *temp = parent->lchild;
            free(parent);
            return temp;
        }

    struct node *temp = Isuccessor(parent->rchild);
    parent->value = temp->value;
    parent->rchild = NodeDeletion(parent->rchild, temp->value);

}
    return parent;
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


    printf("\n Delete 41\n");
    parent = NodeDeletion(parent, 41); 
    printf("Inorder traversal after deletion of a node in Binary Search Tree: ");
    Inorder(parent); 


}

//Work Cited: https://www.geeksforgeeks.org/deletion-in-binary-search-tree/ 