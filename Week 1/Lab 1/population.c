#include <cs50.h>
#include <stdio.h>

int start_size(void);
int end_size(int n);
int progress(int m, int n);
int main(void)
{
    // TODO: Prompt for start size
    int n = start_size();

    // TODO: Prompt for end size
    int m = end_size(n);

    // TODO: Calculate number of years until we reach threshold
    int y = progress(m, n);
    // TODO: Print number of years
    printf("Years: %i\n", y);
}

int start_size(void)
{
    int n;
    do
    {
        n = get_int("Start size: ");
    }
    while (n < 9);
    return n;
}

int end_size(int n)
{
    int m;
    do
    {
        m = get_int("End size: ");
    }
    while (m < n);
    return m;
}

int progress(int m, int n)
{
    int y = 0;
    while (n < m)
    {
        n = n + n / 3 - n / 4;
        y++;
    }
    return y;
}
