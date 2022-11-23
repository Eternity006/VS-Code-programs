#include <stdio.h>
#define MAX 20
int pattern(int n,int k,int l,int arr[MAX][MAX])
{
    int x,y,i,j;
    if(n>0)
    {
        for( x=1,i=k;x<2*n;x++,i++)
        {
            for(y=1,j=k;y<2*n;y++,j++)
            {
                arr[i][j]=0;
                if(x==1||x==2*n-1||y==1||y==2*n-1)
                arr[i][j]=arr[i][j]+n;
            }
        }
        l++;
        pattern(n-1,l,l,arr);
    }
}
void display(int n,int arr[MAX][MAX])
{
    int i,j;
    for(i=0;i<2*n-1;i++)
    {
        printf("\n");
        for(j=0;j<2*n-1;j++)
        printf("%d ",arr[i][j]);
    }
}
void main()
{
    int n,arr[MAX][MAX];
    printf("Enter the number:");
    scanf("%d",&n);
    pattern(n,0,0,arr);
    display(n,arr);
}