#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void cipher(string plaintext, string key);
bool repeat(string key);

int main(int argc, string argv[])
{

    if (argc == 2)
    {
        if (strlen(argv[1]) != 26)
        {
            printf("Key must contain 26 characters");
            return 1;
        }
        for (int i = 0; i < 26; i++)
        {
            if (repeat(argv[1]) == true)
            {
                return 1;
            }
            if (isalpha(argv[1][i]) == false)
            {
                return 1;
            }
        }
        string plaintext = get_string("Plaintext: ");
        printf("ciphertext: ");
        cipher(plaintext, argv[1]);
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    printf("\n");
    return 0;
}

void cipher(string plaintext, string key)
{
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]))
        {
            printf("%c", toupper(key[plaintext[i] - 'A']));
        }
        else if (islower(plaintext[i]))
        {
            printf("%c", tolower(key[plaintext[i] - 'a']));
        }
        else if (isalpha(plaintext[i]) == false)
        {
            printf("%c", plaintext[i]);
        }
    }
}

bool repeat(string key)
{
    for (int i = 0, j = strlen(key); i < j; i++)
    {
        for (int k = i + 1; k < j; k++)
        {
            if (tolower(key[i]) == tolower(key[k]))
            {
                return true;
            }
        }
    }
    return false;
}
