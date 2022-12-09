#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int *a, int n)
{
    int i, j;
// Comparing the element at the zeroth index  with the rest of the element.
// If the zeroth element is the smallest element then no change is made. 
// If the zeroth element is bigger than swapping is done with the smallest one.
// The process is repeated at every index  
    for(i=0; i<n; i++)
    for(j=0; j<n-i-1; j++)
    if (a[j]>a[j+1])

    {
        int small = a[j];
        a[j]= a[j+1];       //Swap Code
        a[j+1]= small; 
    }
}

void arrayDisplay(int a[], int n){
	int i;
	for(i=0; i<n; i++){
        BubbleSort(a,n);
		printf(" %d", a[i]); }
        printf("\n");
   




	}

int main()
{
	int a[]= {34, 54, 65, 12, 3, 33, 23, 15, 56, 79, 24, 25, 88};
	int n = sizeof(a) / sizeof(a[0]);

    
	printf("BubbleSort:  "); 
    arrayDisplay(a,n);


    return 0; 
    
}
