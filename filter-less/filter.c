#include "helpers.h"
#include <math.h>

#define RED_COLOR 0
#define GREEN_COLOR 1
#define BLUE_COLOR 2

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Calculate the average SINGLE apixel value
    for(int r = 0; r < height; r++){
        for(int c = 0; c < width; c++){
                int g =round((image[r][c].rgbtBlue + image[r][c].rgbtRed + image[r][c].rgbtGreen) / 3.0);
                image[r][c].rgbtBlue = g;
                image[r][c].rgbtRed = g;
                image[r][c].rgbtGreen = g;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int r = 0; r < height; r++){
        for(int c = 0; c < width; c++){
            int red = round(0.393 * image[r][c].rgbtRed + 0.769 * image[r][c].rgbtGreen + 0.189 * image[r][c].rgbtBlue);
            int blue = round(0.349 * image[r][c].rgbtRed + 0.686 * image[r][c].rgbtGreen + 0.168 * image[r][c].rgbtBlue);
            int green = round(0.272 * image[r][c].rgbtRed + 0.534 * image[r][c].rgbtGreen + 0.131 * image[r][c].rgbtBlue);

            if(red > 255 || blue > 255 || red > 255){
                image[r][c].rgbtBlue = 255;
                image[r][c].rgbtRed = 255;
                image[r][c].rgbtGreen = 255;
            }else{
                image[r][c].rgbtBlue = blue;
                image[r][c].rgbtRed = red;
                image[r][c].rgbtGreen = green;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE t;
    for(int r = 0; r < height; r++){
        for(int c = 0; c < width / 2; c++){
            // Storing in a tempv the original value, change the first half rc to
            // last half rc value,and get from temp the original first half to 2nd half place
            t = image[r][c];
            image[r][c] = image[r][width - c - 1];
            image[r][width - c - 1] = t;
        }
    }
    return;
}

// Blur image
int blurring(int i, int j, int height, int width, RGBTRIPLE image[height][width], int color_position){
    float count = 0;
    int sum = 0;
    for(int r = i - 1; r <= (i + 1); r++){
         for(int c = j - 1; c <= (j + 1); c++){
             if(r < 0 || r >= height || c < 0 || c > width){
                 continue;
             }
             if(color_position == RED_COLOR){
                 sum += image[r][c].rgbtRed;
             }else if(color_position == GREEN_COLOR){
                 sum += image[r][c].rgbtGreen;
                }else{
                 sum += image[r][c].rgbtBlue;
                 }
                 count++;
         }
    }
    return round(sum/count);
}
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for(int r = 0; r < height; r++){
            for(int c = 0; c < width; c++){
                copy[r][c] = image[r][c];
                }
            }
    for(int r = 0; r < height; r++){
        for(int c = 0; c < width; c++){
            image[r][c].rgbtRed = blurring(r, c, height, width, copy, RED_COLOR);
            image[r][c].rgbtBlue = blurring(r, c, height, width, copy, BLUE_COLOR);
            image[r][c].rgbtGreen = blurring(r, c, height, width,copy, GREEN_COLOR);
        }
    }
    return;
}
