#include <stdio.h>
int main()
{
    FILE *ptr=NULL;
    ptr=fopen("s1.txt", "r+   ");
    char ch;
    int count=0;
    while((ch=fgetc(ptr))!=EOF)
    {
        count++;
    }
    fclose(ptr);
    printf("%d", count);
}