#include <stdio.h>
int binarysearch(int [], int ,int );
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }
    binarysearch(a,0,n-1);
}
int binarysearch(int a, int low, int high)
{
    mid=(low+high)/2;
    if(low == high)
    {
        printf("Element found\n");
    }
    else if(a[low]<a[mid])
    {
        
    }
}