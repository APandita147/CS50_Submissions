#include <cs50.h>
#include <math.h>
#include <stdio.h>

void validity(long n);
int main(void)
{ // ask user to put in card number
    long n = get_long("Number: ");

    // check if it is a valid card number or not
    validity(n);
}

void validity(long n)
{
    int odd_num = 0;
    int even_num = 0;
    int count = 1;
    long num = n;
    while (num > 0)
    {
        for (int i = 1; num > 0; i++)
        {
            if (i % 2 == 0)
            {
                int m;
                int r = 2 * (num % 10);
                while (r > 0)
                {
                    m = r % 10;
                    even_num += m;
                    r = r / 10;
                }
            }

            else if (i % 2 != 0)
            {
                odd_num += (num % 10);
            }

            num = num / 10;
            count++;
        }
    }

    int luhn_algo = odd_num + even_num;
    int first_dig = n / pow(10, count - 2);
    int first_two_dig = n / pow(10, count - 3);

    if (count < 13 || count > 17 || luhn_algo % 10 != 0)
    {
        printf("INVALID\n");
    }

    else if ((count == 16) & (first_two_dig == 34 || first_two_dig == 37))
    {
        printf("AMEX\n");
    }

    else if ((first_dig == 4) & (count == 14 || count == 17))
    {
        printf("VISA\n");
    }

    else if (first_two_dig > 50 & first_two_dig < 56 & count == 17)
    {
        printf("MASTERCARD\n");
    }

    else
    {
        printf("INVALID\n");
    }
}
