/* Code for MergeSort */

#include <stdio.h>
#include <stdlib.h>

void MergeSort(int a[], int m, int n ) /*Dividing the array a[] into two subarrays i[] and j[]*/
{
    if (n > m) /* Which two subarrays have the smaller number of elements*/
    {
        int k = m + (n-m) / 2 ;
        MergeSort(a, m,k); /* Self referential call to sort i[]*/
        MergeSort(a, k+1, n); /*Self referential call to sort subarray j[]*/

        Merge(a, m, k, n); /*Now again merging the sorted subarrays*/

    }
}

/*Now we will define the algorithm for Merging two subarrays*/
void Merge(int a[], int A, int G, int Z)
{
    /* Let *L = a[A..G] and *M = a[G+1..Z]; they are sorted subarrays*/
    int n1 = G - A +1 ; /* Finding the number of elements in subarray a[i]*/
    int n2 = Z - G;     /* The same no. of elements in a[j]*/

    int L[n1],  M[n2];
    for (int i =0; i<n1; i++)   /* Traversing through the subarray L*/
    L[i] = a[A+i];
    
    for(int j =0; j<n2; j++)  /* Traversing through the subarray M*/
    M[j] = a[G + j + 1];

    int i, j, k; i=0; j=0; k = A; /*Considering the indices of the main array and the subarray*/

    while (i< n1 && j < n2)
    {
        if (L[i] < M[j])
        { a[k] = L[i]; i++; }

        else
        { a[k] = M[j]; j++;}
        k++;
    }

    while (n1 > i) { a[k] = L[i]; i++; k++; }

    while (n2>j) {a[k] = M[j]; j++; k++;}

}

void DisplayArray(int a[], int n)
{
    for (int i=0; i<n; i++)
    printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int a[]= { 64, 14, 14, 33, -32, 44, 0, 31, 11, 60, 60, -543, -111111111};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Sorted array: \n"); 
    MergeSort(a, 0, n-1);
    DisplayArray(a, n); 
}


/* The above code was inspired from https://www.programiz.com/dsa/merge-sort */
