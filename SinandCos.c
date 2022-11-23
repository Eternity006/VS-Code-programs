#include <stdio.h>
#include <conio.h>
#include <math.h>
#define MAX_TERM 20000
#define PI 3.141592653
float normalize(float x)
{
    while(!((x>=0.00000000)&&(x<=2*PI)))
    {
        if(x<0.000000000)
            x+=2*PI;
        if(x>2*PI)
            x-=2*PI;        
    }
    return x;
}
float my_sin(float x)
{
    float s=0.0, t;
    int i;
    x=normalize(x);
    t=x;
    for(i=1;i<MAX_TERM;i++)
    {
        s=s+t;
        t*=-((x*x)/((2*i+1)*2*i));
    }
    return s;
}
float my_cos(float x)
{
     float s=0.0, t;
    int i;
    x=normalize(x);
    t=x;
    for(i=1;i<MAX_TERM;i++)
    {
        s=s+t;
        t*=-(x*x)/((2*i-1)*2*i);
    }
    return s;
}
void main()
{
    float x=105.0;
    printf("\n Function defined by you: cos(%f)=%f \n Standard Library Function: cos(%f)=%f", x,my_cos(x),x,cos(x));
    printf("\n Function defined by you: sin(%f)=%f \n Standard Library Function: sin(%f)=%f", x,my_sin(x),x,cos(x));
}