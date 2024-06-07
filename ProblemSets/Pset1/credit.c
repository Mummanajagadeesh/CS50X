#include <cs50.h>
#include <stdio.h>

int checksum(long number); // checksum function
int len(long number);      // function to find length of the given number

int main(void)
{
    long number = get_long("Number: ");
    long n = number;
    while (n >= 100)
    {
        n /= 10;
    }
    // n will now hold the first 2 digits of a number
    if (checksum(number) % 10 == 0)
    {
        if (((len(number) == 13) || (len(number) == 16)) && (n / 10 == 4))
        {
            printf("VISA\n");
        }
        else if ((len(number) == 15) && ((n == 34) || (n == 37)))
        {
            printf("AMEX\n");
        }
        else if ((len(number) == 16) && (n > 50) && (n < 56))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

int len(long number)
{
    int length = 0;
    while (number != 0)
    {
        number /= 10;
        length++;
    }
    return length;
}

int checksum(long number)
{
    int sum_01 = 0,
        sum_02 = 0;   // sum_01 is the second-to-last digit sum and sum_02 is the sum of rem digits
    int i = 0, k = 0; // parity of "i" is used to alternate bw sum_01 and sum_02 and k holds the
                      // value to be added
    while (number != 0)
    {
        k = 2 * (number % 10);
        if (i % 2 != 0)
        {
            k = (k < 10) ? k : (k / 10 + k % 10);
            sum_01 += k;
        }
        else
        {
            sum_02 += (k / 2);
        }
        i++;
        number /= 10;
    }

    return (sum_02 + sum_01); // overall sum will be returned as the output of the func
}
