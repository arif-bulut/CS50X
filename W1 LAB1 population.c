#include <cs50.h>
#include <stdio.h>
int main(void)
{
    // TODO: Prompt for start size
int y;
    do
    {
        y = get_int("Starting Size: ");
    }
    while (y < 9);
    // TODO: Prompt for end size
int z;
    do
    {
        z = get_int("End Size: ");
    }
    while (y > z);
    // TODO: Calculate number of years until we reach threshold
int x = 0;
    if(y < z)
    do
    {
        y = y+ (y / 3) - (y / 4);
        x++;
    }
    while(y < z);
    // TODO: Print number of years
    printf("Years: %i\n", x);
}