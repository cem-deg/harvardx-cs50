#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Programın yalnızca tek bir komut satırı argümanıyla çalıştırıldığından emin ol
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // argv[1]'deki her karakterin rakam olduğundan emin ol
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // argv[1]'i string'den int'e çevir
    int k = atoi(argv[1]);

    // Kullanıcıdan düz metin (plaintext) al
    string plaintext = get_string("plaintext:  ");

    // Şifreli metni (ciphertext) yazdırmaya başla
    printf("ciphertext: ");

    // Düz metindeki her karakter için:
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];

        // Büyük harf ise döndür
        if (isupper(c))
        {
            printf("%c", (char) ((c - 'A' + k) % 26 + 'A'));
        }
        // Küçük harf ise döndür
        else if (islower(c))
        {
            printf("%c", (char) ((c - 'a' + k) % 26 + 'a'));
        }
        // Harf değilse olduğu gibi yazdır
        else
        {
            printf("%c", c);
        }
    }

    // Yeni satır ekle ve programı bitir
    printf("\n");
    return 0;
}