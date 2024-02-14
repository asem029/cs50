#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i =0;i<height;i++)
    {
        for (int j=0;j<width;j++)
        {
           int a= round((image[i][j].rgbtBlue+image[i][j].rgbtRed+image[i][j].rgbtGreen)/3);
           image[i][j].rgbtBlue=a;
           image[i][j].rgbtGreen=a;
           image[i][j].rgbtRed=a;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sRed,sGreen,sBlue;
    for (int i =0;i<height;i++)
    {
        for (int j=0;j<width;j++)
        {
         sRed=round(0.393*image[i][j].rgbtRed+0.769*image[i][j].rgbtGreen+0.189*image[i][j].rgbtBlue);
         sGreen=round(0.349*image[i][j].rgbtRed+0.686*image[i][j].rgbtGreen+0.168*image[i][j].rgbtBlue);
         sBlue=round(0.272*image[i][j].rgbtRed+0.534*image[i][j].rgbtGreen+0.131*image[i][j].rgbtBlue);
         if(sRed>255)
         {image[i][j].rgbtRed=255;}
         else 
         {image[i][j].rgbtRed=sRed;}
         if(sGreen>255)
         {image[i][j].rgbtGreen=255;}
         else 
         {image[i][j].rgbtGreen=sGreen;}
         if(sBlue>255)
         {image[i][j].rgbtBlue=255;}
         else 
         {image[i][j].rgbtBlue=sBlue;}
        }
    }    
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i =0;i<height;i++)
    {
        for (int j=0;j<width/2;j++)
        {
            int tmp1=image[i][j].rgbtRed;
            image[i][j].rgbtRed=image[i][width-j].rgbtRed;
            image[i][width-j].rgbtRed=tmp1;
            
            int tmp2=image[i][j].rgbtBlue;
            image[i][j].rgbtBlue=image[i][width-j].rgbtBlue;
            image[i][width-j].rgbtBlue=tmp2;
            
            int tmp3=image[i][j].rgbtGreen;
            image[i][j].rgbtGreen=image[i][width-j].rgbtGreen;
            image[i][width-j].rgbtGreen=tmp3;
            
        }
    }    
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int red [height][width];
    int green [height][width];
    int blue [height][width];
    for (int i =0;i<height;i++)
    {
        for (int j=0;j<width;j++)
        {
          red [i][j]=round((image[i][j].rgbtRed+image[i][j+1].rgbtRed+image[i][j-1].rgbtRed+image[i+1][j].rgbtRed+image[i+1][j+1].rgbtRed+image[i+1][j-1].rgbtRed+image[i-1][j].rgbtRed+image[i-1][j+1].rgbtRed+image[i-1][j-1].rgbtRed)/9);
          green [i][j]=round((image[i][j].rgbtGreen+image[i][j+1].rgbtGreen+image[i][j-1].rgbtGreen+image[i+1][j].rgbtGreen+image[i+1][j+1].rgbtGreen+image[i+1][j-1].rgbtGreen+image[i-1][j].rgbtGreen+image[i-1][j+1].rgbtGreen+image[i-1][j-1].rgbtGreen)/9);
          blue [i][j]=round((image[i][j].rgbtBlue+image[i][j+1].rgbtBlue+image[i][j-1].rgbtBlue+image[i+1][j].rgbtBlue+image[i+1][j+1].rgbtBlue+image[i+1][j-1].rgbtBlue+image[i-1][j].rgbtBlue+image[i-1][j+1].rgbtBlue+image[i-1][j-1].rgbtBlue)/9);
            
        }
    }
    for (int i =0;i<height;i++)
    {
        for (int j=0;j<width/2;j++)
        {
         image[i][j].rgbtRed= red [i][j];
         image[i][j].rgbtGreen= green [i][j];
         image[i][j].rgbtBlue= blue [i][j];
        }
    }    
    return;
}
