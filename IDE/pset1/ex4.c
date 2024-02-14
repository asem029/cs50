#include <math.h>
#include <stdio.h>
#include <cs50.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string text = get_string("text:\n");
    int l=0;
    int s=0;
    int w=0;
    int x=strlen(text);
    for (int i = 0; i < x ; i++)
    {
        if (isspace(text))
        {
            w++;
        }
    }
    printf("%i",w);
}
