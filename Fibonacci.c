#include<stdio.h>
int fibonacci(int);
int fib_iteration(int);
int main()
{
    int n; long m=0; long d=0;
    printf("Enter the value of the number:");
    scanf("%d", &n);
    d=fib_iteration(n);
    m=fibonacci(n);
    printf("The fibonacci value of the number %d is %d", n, d);
    printf("\nThe fibonacci value of the number %d is %d", n, m);
}
int fibonacci(int n)
{
    if(n==1||n==2)
      return n-1;
    else
      return fibonacci(n-1)+fibonacci(n-2);  
}
int fib_iteration(int n)
{
    int a=0;int b=1;
    for(int i=0;i<n-1;i++)
    {
        b=a+b;
        a=b-a;
    }
    return a;
}