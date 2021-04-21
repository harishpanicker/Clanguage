/*WAP to add two numbers using pointers*/
#include <stdio.h>
int main()
{
   int first, second, *p=NULL, *q=NULL, sum=0;

   printf("Enter two integers to add\n");
   scanf("%d%d", &first, &second);

   p = &first;
   q = &second;

   sum = *p + *q;

   printf("Sum of the numbers = %d\n", sum);

   return 0;
}
