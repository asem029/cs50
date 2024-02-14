#include <stdio.h>
#include <cs50.h>
#include <unistd.h>
int main(void)
{
    int h;
    
    do{
        h =get_int("height: ");
        
        if (h<1||h>8)
       {printf ("enter naumbers between 1 and 8\n");} 
    }
    while (h<1||h>8);
    
    
    for (int i=0 ; i<h+1; i++)
    {
  for (int r=0;r<h-i+1; r=r+1)
   {
       printf (" ");}  
       for (int t=h-i;t<h;t++)
       {printf("#");}
   
   printf ("\n");}
}