#include<stdio.h>
int fact(int N)
{
if(N==0 || N==1)
{
return 1;
}
else
{
return N*fact(N-1);
}

}
int main()
{
int N;
printf("enter the N value :");
scanf("%d",&N);
int sum=fact(N);
printf(" the factorial of given number:%d\n",sum);
return 0;
}
