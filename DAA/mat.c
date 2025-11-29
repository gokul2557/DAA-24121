#include<stdio.h>
int main()
{
int i,j,arr[3][3];
//input matrix values
for(i=0;i<3;i++)
{
 for( j=0;j<3;j++)
 {
 scanf("%d",&arr[i][j]);
 }
 }
 
 //transpose
 for( i=0;i<3;i++)
{
 for( j=1;j<3;j++)
 {
       int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
 }
 }
 
 printf("Transpose of the matrix:\n");
    for( i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

 return 0;
 }
 
 
 
 
