// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Hash table node
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Bucket sayısı (daha fazla bucket = daha hızlı arama)
const unsigned int N = 1000;

// Hash table
node *table[N];

// Yüklenen kelime sayısı
unsigned int word_count = 0;

// Kelimeyi hash table'da arar, varsa true döner
bool check(const char *word)
{
    // Kelimeyi küçük harfe çevir
    char lower[LENGTH + 1];
    for (int i = 0; word[i] != '\0'; i++)
    {
        lower[i] = tolower(word[i]);
        lower[i + 1] = '\0';
    }

    // Hash değerini bul ve o bucket'ı tara
    unsigned int index = hash(lower);
    node *cursor = table[index];
    while (cursor != NULL)
    {
        if (strcmp(cursor->word, lower) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Kelimeyi hash değerine çevirir
unsigned int hash(const char *word)
{
    unsigned int sum = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        sum += tolower(word[i]);
    }
    return sum % N;
}

// Sözlüğü belleğe yükler
bool load(const char *dictionary)
{
    // Dosyayı aç
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];

    // Dosyadan her kelimeyi oku
    while (fscanf(file, "%s", word) != EOF)
    {
        // Yeni node oluştur
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            fclose(file);
            return false;
        }

        // Kelimeyi kopyala ve hash table'a ekle
        strcpy(n->word, word);
        unsigned int index = hash(word);
        n->next = table[index];
        table[index] = n;
        word_count++;
    }

    fclose(file);
    return true;
}

// Sözlükteki kelime sayısını döner
unsigned int size(void)
{
    return word_count;
}

// Tüm belleği serbest bırakır
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}