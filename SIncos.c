#include <stdio.h>
#include <math.h>
#define pi 3.141592653
#define accuracy 0.000001
#define max_term 1000
float normalisation(float x)
{
    while(!(x>=0.0&&x<=2*pi))
    {
    if(x<0.0)
        x+=(2*pi);
    else if(x>2*pi)
        x-=2*pi;
    
    }
    return x;
}

float my_sin(float x)
{
    float sum=0.0,term;
    int i;
    x=normalisation(x);
    term=x;
    for(i=1;i<max_term;i++)
    {
        sum+=term;
        term*=-(x*x)/((2*i)*((2*i)+1));
    }
    return sum;
}

float my_cos(float x)
{
    float sum=0.0,term;
    int i;
    x=normalisation(x);
    term=1.0;
    for(i=1;i<max_term;i++)
    {
        sum+=term;
        term*=-(x*x)/((2*i)*((2*i)-1));
    }
    return sum;
}

void main()
{
    float x;
    printf("Enter a value to check: ");
    scanf("%f",&x);
    printf("Value of sin(%f) is : %.5f\n",x,my_sin(x));
    printf("Value of library defined sin(%f) is : %.5f\n",x,sin(x));
    printf("Value of cos(%f) is : %.5f\n",x,my_cos(x));
    printf("Value of library defined cos(%f) is : %.5f\n",x,cos(x));
}