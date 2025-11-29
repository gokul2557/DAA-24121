#include<stdio.h>
int main()
{
int N,sum=0,i,p;
printf("enter the number of Natural Number N:");
scanf("%d",&N);
for(i=1;i<N;i++)
{ p=N*N;
 sum=sum+p;
 }
 printf("the sum of squares of a N Number%d",sum);
 }

