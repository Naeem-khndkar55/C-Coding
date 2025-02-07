#include <stdio.h>
#include <string.h>

const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
#define CHARSET_SIZE 62

int findIndex(char c)
{
    for (int i = 0; i < CHARSET_SIZE; i++)
    {
        if (charset[i] == c)
            return i;
    }
    return -1;
}

int main()
{
    char plaintext[256], key[256], ciphertext[256], decryptedtext[256];

    printf("Enter plaintext: ");
    scanf("%255s", plaintext);
    printf("Enter key: ");
    scanf("%255s", key);

    int textLen = strlen(plaintext);
    int keyLen = strlen(key);

    for (int i = 0; i < textLen; i++)
    {
        int textIndex = findIndex(plaintext[i]);
        int keyIndex = findIndex(key[i % keyLen]);

        if (textIndex == -1 || keyIndex == -1)
        {
            ciphertext[i] = plaintext[i];
        }
        else
        {
            ciphertext[i] = charset[(textIndex + keyIndex) % CHARSET_SIZE];
        }
    }
    ciphertext[textLen] = '\0';

    printf("Ciphertext: %s\n", ciphertext);

    for (int i = 0; i < textLen; i++)
    {
        int cipherIndex = findIndex(ciphertext[i]);
        int keyIndex = findIndex(key[i % keyLen]);

        if (cipherIndex == -1 || keyIndex == -1)
        {
            decryptedtext[i] = ciphertext[i];
        }
        else
        {
            decryptedtext[i] = charset[(cipherIndex - keyIndex + CHARSET_SIZE) % CHARSET_SIZE];
        }
    }
    decryptedtext[textLen] = '\0';

    printf("Decrypted text: %s\n", decryptedtext);

    return 0;
}
