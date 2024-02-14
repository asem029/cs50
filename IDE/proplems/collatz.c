#include <math.h
#include <cs50.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
int collatz (int x);  
int main (void)
{

   int n= get_int ("number:");
    collatz(n);
    printf("%i times\n",collatz(n));
}
int collatz (int x)   
{
    int t=0;
    if (x==1)
    {return 0;}
    else if ((x%2)==0)
    {
     return 1+collatz(x/2);
        t++;
    }
    else
    {
     return 1+ collatz(3*x+1);
    t++;
    }
    return t;
}
