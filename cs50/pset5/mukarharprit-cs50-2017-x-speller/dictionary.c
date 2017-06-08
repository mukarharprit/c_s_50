/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "dictionary.h"

#define SIZE_htable 3000

int countWord = 0;

//define the structure
typedef struct node
{
    char* word;
    struct node* next;
}
node;

//htable of linked list
node* htable[SIZE_htable];

int hvalue(const char* s)
{
    int wordLength = 0, hval = 0;
    wordLength = strlen(s);
    for(int i = 0; i < wordLength; i++)
    {
        hval += s[i];
    }
    return (hval % SIZE_htable);
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    char notCheck[LENGTH + 1];

    char lCase;

    for(int i = 0, n = strlen(word); i < n; i++)
    {
        lCase = tolower(word[i]);

        notCheck[i] = (char)lCase;
    }
    
    
    notCheck[strlen(word)] = '\0';
    
    int hval = hvalue(notCheck);

    node* temp = htable[hval];

    if(temp == NULL)
    {
        return false;
    }
    while(temp != NULL)
    {
        if(!strcmp(notCheck, temp -> word))
        {
            return true;
        }
        temp = temp -> next; 
    }
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    
    int hval = 0;

    char dict_word[LENGTH + 1];

    FILE* file = fopen(dictionary, "r");

    if(file == NULL)
    {
        return false;
    }
    
    while(fscanf(file, "%s\n", dict_word) != EOF)
    {
        node* n_list = malloc(sizeof(node));

        n_list -> word = malloc(strlen(dict_word) + 1);

        strcpy(n_list -> word, dict_word);

        hval = hvalue(dict_word);

        countWord++;
        if(htable[hval] == NULL)
        {
            htable[hval] = n_list;
            n_list -> next = NULL;
        }
        else
        {
            n_list -> next = htable[hval];
            htable[hval] = n_list;
        }
    }
    fclose(file);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    
    return countWord;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    node* node1 = NULL;

    node* node2 = NULL;
    
    for(int i = 0; i < SIZE_htable; i++)
    {
        node1 = htable[i];

        if(node1 && !node1 -> next)
        {
            free(node1 -> word);

            free(node1);
        }
        else
        {
            while(node1)
            {
                node2 = node1 -> next;

                free(node1 -> word);

                free(node1);

                node1 = node2;
            }
        }
        htable[i] = NULL;
    }
    return true;
}
