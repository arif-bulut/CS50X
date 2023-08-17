#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string first = get_string("What is your name? ");
    printf("Hello, %s.\n", first);
}