
//  Codes for Insertion Sort using an array
#include <stdio.h>
#include <stdlib.h>

void isort(int Arr[], int n){
    int i, sortp, j;
    for (i=1; i<n; i++){
    sortp = Arr[i];                                 //Code for sorting the unsorted part of the array
    j = i - 1;                                      // At first, we consider the element at the zeroth index as the sorted
                                                    // part of the array, then we compare it from the next element and if found smaller
                                                    // we swap the elements. After the swap we check the sorted part of the array
                                                    // whether further swapping is required or not by comparing all the elements present 
                                                    // in the sorted array.

    while (j >=0 &&  sortp < Arr[j] ){
        Arr[j +1] = Arr[j];                         
        j = j-1;

        }
     Arr[j+1] = sortp;
 }
}

void ArrayDisplay(int Arr[], int n){
    int i;
    for (i=0; i<n; i++)
    printf("%d ", Arr[i]);

    printf("\n");
}

int main(){
    int Arr[]= { 2, 84, -93, 1, 83, -17, 12};
    int n = sizeof(Arr) / sizeof(Arr[0]);


    printf("Insertion Sort: "); 
    isort(Arr, n); 
    ArrayDisplay(Arr, n);
    

    return 0;

}


/* https://www.geeksforgeeks.org/insertion-sort/ */