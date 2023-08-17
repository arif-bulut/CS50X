#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
int count_letters(string text);
int count_sentences(string text);
int count_words(string text);
int main(void)
{
    string text = get_string("Text: ");
    int letter = count_letters(text);
    int sentence = count_sentences(text);
    int word = count_words(text);
    float L = (float) letter / (float) word * 100;
    float S = (float) sentence / (float) word * 100;
    int index = round((0.0588 * L) - (0.296 * S) - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
int count_letters(string text)
{
    int letter = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letter++;
        }
    }
    printf("%i letters\n", letter);
    return letter;
}
int count_sentences(string text)
{
    int sentence = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentence++;
        }
    }
    printf("%i sentences\n", sentence);
    return sentence;
}
int count_words(string text)
{
    int word = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            word++;
        }
    }
    word++;
    printf("%i words\n", word);
    return word;
}