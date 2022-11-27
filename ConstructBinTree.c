#include <stdio.h>
#include <stdlib.h>

typedef struct bintree {
    int data;
    struct bintree *lchild;
    struct bintree *rchild;
} bintree;

bintree *Nodetree(int data){
    bintree* element = malloc(sizeof(bintree));
    if (element != NULL){
        element ->lchild = NULL;
        element ->rchild = NULL;
        element ->data = data;
    }
    return element;
}

void bintreeprint(bintree *root){
    if (root == NULL){
        printf("empty\n");
        return;
    }
    printf("value = %d\n", root->data);
    printf("lchild\n");
    bintreeprint(root->lchild);

    printf("rchild\n");
    bintreeprint(root->rchild);
    
    

}

int main(){
    bintree *i0 = Nodetree(45);
    bintree *i1 = Nodetree(23);
    bintree *i2 = Nodetree(69);
    bintree *i3 = Nodetree(90);
    bintree *i4 = Nodetree(12);
    bintree *i5 = Nodetree (34);

    i0->lchild = i1;
    i0->rchild = i2;
    i2->lchild = i3;
    i2->rchild = i4;
    i4->lchild = i5;
    printf("The binary tree is \n");
    bintreeprint(i0);

    free(i0);
    free(i1);
    free(i2);
    free(i3);
    free(i4);
    free(i5);
}
