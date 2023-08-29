#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            int avg = round((image[x][y].rgbtRed + image[x][y].rgbtGreen + image[x][y].rgbtBlue) / 3.0);
            image[x][y].rgbtRed = image[x][y].rgbtGreen = image[x][y].rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            int sepiaRed = round(0.393 * image[x][y].rgbtRed + 0.769 * image[x][y].rgbtGreen + 0.189 * image[x][y].rgbtBlue);
            int sepiaGreen = round(0.349 * image[x][y].rgbtRed + 0.686 * image[x][y].rgbtGreen + 0.168 * image[x][y].rgbtBlue);
            int sepiaBlue = round(0.272 * image[x][y].rgbtRed + 0.534 * image[x][y].rgbtGreen + 0.131 * image[x][y].rgbtBlue);
            image[x][y].rgbtRed = sepiaRed > 255 ? 255 : sepiaRed;
            image[x][y].rgbtGreen = sepiaGreen > 255 ? 255 : sepiaGreen;
            image[x][y].rgbtBlue = sepiaBlue > 255 ? 255 : sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE original[height][width];
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            original[x][y] = image[x][y];
        }
    }
    for (int x = 0; x < height; x++)
    {
        for (int y = 0, swap = width - 1; y < width; y++)
        {
            image[x][y] = original[x][swap];
            swap--;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE original[height][width];
    float totalRed, totalGreen, totalBlue;
    int count = 0;
    totalRed = totalGreen = totalBlue = 0;
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            original[x][y] = image[x][y];
        }
    }
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            for (int arrayx = x - 1; arrayx <= x + 1; arrayx++)
            {
                for (int arrayy = y - 1; arrayy <= y + 1; arrayy++)
                {
                    if (arrayx < height && arrayy < width && arrayx >= 0 && arrayy >= 0)
                    {
                        totalRed += original[arrayx][arrayy].rgbtRed;
                        totalGreen += original[arrayx][arrayy].rgbtGreen;
                        totalBlue += original[arrayx][arrayy].rgbtBlue;
                        count++;
                    }
                }
            }
            image[x][y].rgbtRed = round(totalRed / count);
            image[x][y].rgbtGreen = round(totalGreen / count);
            image[x][y].rgbtBlue = round(totalBlue / count);
            count = 0;
            totalRed = totalGreen = totalBlue = 0;
        }
    }
    return;
}