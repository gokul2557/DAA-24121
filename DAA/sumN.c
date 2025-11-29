#include<stdio.h>
int sum(int N)
{ int i;
  int sum=0;
  for( i=1;i<=N;i++)
  {
  sum=sum+i;
  }
  return sum;
}
int main()
{ int N;
 printf("enter the N number :");
 scanf("%d",&N);
 int total=sum(N);
 printf("the sum of N numbers is %d:",total);
 return 0;
 }
 
