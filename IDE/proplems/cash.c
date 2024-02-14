#include <math.h>
#include <stdio.h>
#include <cs50.h>
#include <unistd.h>
float get_v(void);
int main(void)
{
    int i = 0;
    int t = 0;
    float c = get_v();
    int a = round(c * 100);
    while (i <= a - 25)
    {
        i = i + 25;
        t++;
    }
    while (i <= a - 10)
    {
        i = i + 10;
        t++;
    }
    while (i <= a - 5)
    {
        i = i + 5;
        t++;
    }
    while (i <= a - 1)
    {
        i = i + 1;
        t++;
    }
    printf("the least number of coins is %i\n", t);
}
float get_v(void)
{
    float v;   
    do   
    {
        v = get_float("change in dollars\n");
    }
    while (v < 0);
    return v;
}
