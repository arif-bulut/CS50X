#include <cs50.h>
#include <stdio.h>
#include <string.h>
const int BITS_IN_BYTE = 8;
void print_bulb(int bit);
int main(void)
{
    string text = get_string("Message: ");
    for (int i = 0; i < strlen(text); i++)
    {
        int binary[8];
        int decimal_value = text[i];
        for (int x = BITS_IN_BYTE - 1; x > 0; x--)
        {
            binary[x] = decimal_value % 2;
            {
                decimal_value = decimal_value / 2;
            }
        }
        for (int x = 0; x < BITS_IN_BYTE; x++)
        {
            print_bulb(binary[x]);
        }
        printf("\n");
    }
}
void print_bulb(int bit)
{
    if (bit == 0)
    {
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        printf("\U0001F7E1");
    }
}