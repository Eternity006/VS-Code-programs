#include <stdio.h>
int main()
{
    int a;
    scanf("%d", &a);
    int* ptra=&a;
    printf("%p\n " , ptra);
    printf("%d\n ", *ptra);
}