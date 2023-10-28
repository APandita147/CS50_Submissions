#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    float L = (float) count_letters(text) * 100 / count_words(text);
    float S = (float) count_sentences(text) * 100 / count_words(text);
    int grade = round((0.0588 * L - 0.296 * S - 15.8));

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }

    else
        printf("Grade %i\n", grade);
}

int count_letters(string text)
{
    int i = 0;
    int count = 0;

    while (text[i] != 0)
    {
        if (isalpha(text[i]))
        {
            count++;
        }

        i++;
    }
    return count;
}

int count_words(string text)
{
    int j = 0;
    int blanks = 0;

    while (text[j] != 0)
    {
        if (isblank(text[j]))
        {
            blanks++;
        }

        j++;
    }

    return blanks + 1;
}

int count_sentences(string text)
{
    int k = 0;
    int sent = 0;

    while (text[k] != 0)
    {
        if (text[k] == '.' || text[k] == '?' || text[k] == '!')
        {
            sent++;
        }

        k++;
    }

    return sent;
}