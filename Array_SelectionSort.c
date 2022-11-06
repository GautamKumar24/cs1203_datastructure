#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
        *a = *b;
        *b = temp;
    
}

void SelectionSort(int A[], int n)
{
        int i, j, small_index;   // The integer i would transverse till the n-1 indices of the array 'A' 
                                // The integer j would move from i+1 to n in an unsorted part of the array 'A'
                                // The small_index would keep on updating if the lowest element is found in the process of unsorted array
for (i = 0; i < n-1; i++){
    small_index = i;
    for(j = i+1; j < n; j++)
        if (A[small_index] > A[j])          //Finding the smallest integer in the given unsorted array
        small_index = j;

        if (small_index != i)
        swap(&A[i], &A[small_index]);
    }
}



void Arraydisplay(int A[], int len){
    int i;
    for(i = 0; i < len; i++)                //The following code is to print an array
    printf("%d ", A[i]);
    printf("\n");
}



int main(){
    int A[] = { 34, 58, 54, 67, 23, 12};
    int n = sizeof(A)/sizeof(A[0]);
    SelectionSort(A, n);
    printf("Sorted array: \n");
    Arraydisplay(A, n);
    
    return 0;

}
