#include<stdio.h>
#include<stdlib.h>
int main()
{
    int size;
    printf("\n Enter the value of size:");
    scanf("%d", &size);
    int *arr;
    int sum=0;
    arr=(int*)malloc(size *sizeof(int));
    printf("\n Enter the elements of array:");
    for(int i=0;i<size;i++)
    {
        scanf("%d", &arr[i]);
        sum=sum+arr[i];
    }
    printf("\n%d", sum);
}