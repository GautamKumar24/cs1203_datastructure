#include<stdio.h>
int main()
{
  int n, sum=0;

  n = 5;
  

  for(int i=0; i<=n; i++)
  {
     sum += (power( n));
  }

  int power(int n);
    if n = -1
        printf("The input is erraneous");
    elif  (n = 0)
         return 1; 
    else 
    return n*power(n-1);
  

  printf("Sum of squares of first %d natural numbers = %d",
                                                  n, sum);

  return 0;
}