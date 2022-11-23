#include <stdio.h>
#define MAX 20
int main()
{
    int arr[MAX];
    int n;
    scanf("%d", &n);
    printf("\nEnter the element of of the array:");
    for(int k=0;k<n;k++)
    {
        scanf("%d", &arr[k]);
    }
    for(int i=0;i<n-1;i++)
    {
        int key=0;
        key=arr[i];
        for(int j=i+1;j<=n-1;j++)
        {
            int p=0;
            if(key>arr[j])
            {
                p=key;
                key=arr[j];
                arr[j]=p;
                arr[i]=key;
            }
            p=0;
        }
        printf("Pass %d:", i+1);
        for(int m=0;m<n;m++)
        {
            printf("%d ", arr[m]);
        }
        printf("\n");
        
    }
    for(int a=0;a<n;a++)
    {
        for(b=a+1;b<n-1;b++)
        {
            
        }
    }
}