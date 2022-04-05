#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Calculate the average SINGLE apixel value
    for(int r = 0; r < height; r++){
        for(int c = 0; c < width; c++){
                int g =round((image[row][c].rgbtBlue + image[row][c].rgbtRed + image[row][c].rgbtGreen) / 3.0);
                image[row][c].rgbtBlue = g;
                image[row][c].rgbtRed = g;
                image[row][c].rgbtGreen = g;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int r)
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
