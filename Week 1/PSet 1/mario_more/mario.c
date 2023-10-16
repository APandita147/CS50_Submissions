#include <cs50.h>
#include <stdio.h>

int get_height(void);
void print_grid(int m);
int main(void)
{ // taking height from user
    int m = get_height();
    // printing rifted pyramid
    print_grid(m);
}

int get_height(void)
{
    int m;
    do
    {
        m = get_int("Height: ");
    }
    while (1 > m || m > 8);
    return m;

    print_grid(m);
}

void print_grid(int m)
{
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 0; j < m + i + 2; j++)
        {
            if (j > m - i - 1 & j < m || j > m + 1 & j < m + i + 2)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
