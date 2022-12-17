#include <stdio.h>
#include <stdlib.h>

int n = 0; 
void Heapify(int a[], int b, int n)
{
    if (n == 1)
    {
        printf("No Heapification is required");
    }
    else 
     {   int big = b; /*picking up any element from the array to big*/
        int lchild = 2*b + 1; /*lchild is an index in the given array that represents the left child in a complete Binary Tree*/
        int rchild = 2*b + 2; /*rchild is an index in the given array that represents the right child in a complete binary tree*/
//Process of creating heaps from a given array
        if (lchild < n && a[big] < a[lchild])
            big = lchild;
        
        if (rchild < n && a[big] < a[rchild])
            big = rchild;
// Self referential function to heapify the heaps formed
        if (big != b)
        {
            swap(&a[b], &a[big]); 
            Heapify(a, big, n);
        }
     }
     
}

void Insert(int a[], int val)
{
    if ( n == 0)
    {
        a[0] = val;
        n += 1;
    }
    else
    {
        a[n] = val;
        n += 1;
        for (int i = n /2 - 1; i>=0; i--)
        {
            Heapify(a, i, n);

        }
    }
}

void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
} 

void RootDelete(int a[], int nval)
{
    int i;
    for (i=0; i<n; i++)
    {
        if (nval ==a[i])
        break;
    }
    swap(&a[i], &a[n-1]); 
    n-=1;
    for (int i = n/2 -1; i>=0; i--)
    {
        Heapify(a, i, n);

    }
}
void DisplayArray(int a[], int n)
{
  for (int i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");
  
}

int main()
{
    int a[10]; 

  Insert(a, 13);
  Insert(a, 4);
  Insert(a, 19);
  Insert(a, 55);
  Insert(a, 42); 
  Insert(a, 41);
  Insert(a, 98);
  Insert(a, 66);
  Insert(a, 57);
  Insert(a, 33);
  Insert(a, 11);
  Insert(a, 19);
  Insert(a, 78);

  
  
   printf("Max Heap: ");
    DisplayArray(a, n); 

    RootDelete(a, 57);
    printf("array after the deletion: "); 
    DisplayArray(a, n); 

     


}

// Inspired by: https://www.programiz.com/dsa/heap-data-structure. 

