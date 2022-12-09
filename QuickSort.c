// Code for QuickSort using an array 

#include <stdio.h>
#include <stdlib.h>

void QuickSort(int a[], int lw, int hi)
{
    if (hi > lw)
    {
        int pIndex = Partition(a, lw, hi);
        QuickSort(a, lw, pIndex - 1);
        QuickSort(a, pIndex + 1, hi);
    }
}

//As partition is a just a number
int Partition(int a[], int lw, int hi)
{
    int Pivot = a[hi]; //In general picking the last element of an array as an pivot element and updating it 
    int i = (lw -1);   

    for(int j = lw; j<hi; j++)  // Traversing to the left of an array
    // Comparing every element to the left of an array with the pivot element
    {
        if (a[j]<= Pivot)   // Elements less than the pivot are put to the left of the pivot
                            // Elements greater than the pivot are put to the right of the pivot 
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i+1], &a[hi]);
    return (i +1);

}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void DisplayArray(int a[], int n)
{
    for (int i=0; i<n; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int a[]= { 34, 54, 33, 52, 2, 89, 23};
    int n = sizeof(a) / sizeof(a[0]);

    QuickSort(a, 0, n-1);
    DisplayArray(a, n); 
}

/* https://www.programiz.com/dsa/quick-sort */