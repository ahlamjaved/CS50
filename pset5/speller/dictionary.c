/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "dictionary.h"

// creates a global variable to count the size
int DICTIONARY_SIZE = 0;

// create HASH_TABLE
node* HASH_TABLE[SIZE] = {NULL};

// hash function
int hash (const char *word)
{
    int hash = 0;
    int n;
    for (int i = 0; word[i] != '\0'; i++)
    {
        // ensures character is a letter
        if(isalpha(word[i]))
            n = word [i] - 'a' + 1;

        // if the character is a comma
        else
            n = 27;

        hash = ((hash << 3) + n) % SIZE;
    }
    return hash;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // TODO
    // opens up the dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
        return false;

    // stores word in array
    char word[LENGTH + 1];

    // scans file while loading each word into the hash table
    while (fscanf(file, "%s\n", word)!= EOF)
    {
        // increments the size of the dictionary
        DICTIONARY_SIZE++;

        // allocates more memory for new word
        node* NEW_WORD = malloc(sizeof(node));

        // puts word in new node
        strcpy(NEW_WORD->word, word);

        // locates the index of the array which the word is to go into
        int index = hash(word);

        // insert into index of the HASH_TABLEs that appear to be empty
        if (HASH_TABLE[index] == NULL)
        {
            HASH_TABLE[index] = NEW_WORD;
            NEW_WORD->next = NULL;
        }

        // append at location of index if HASH_TABLE is not empty
        else
        {
            NEW_WORD->next = HASH_TABLE[index];
            HASH_TABLE[index] = NEW_WORD;
        }
    }

    // close file
    fclose(file);

    // success
    return true;
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    // TODO
    // creates a temp variable of the word but in lowercase
    char temp[LENGTH + 1];
    int len = strlen(word);
    for(int i = 0; i < len; i++)
        temp[i] = tolower(word[i]);
    temp[len] = '\0';

    // locates the index of the array which the word is to go into
    int index = hash(temp);

    // returns an error if the index is empty within the HASH_TABLE
    if (HASH_TABLE[index] == NULL)
    {
        return false;
    }

    // creates a pointer to compare to the word itself
    node* pointer = HASH_TABLE[index];

    // iterate through words and compare of the index isnt empty in the hasthtable
    while (pointer != NULL)
    {
        if (strcmp(temp, pointer->word) == 0)
        {
            return true;
        }
        pointer = pointer->next;
    }

    // return error if word not found
    return false;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    // return the number of words if the dictionary is loaded
    if (DICTIONARY_SIZE > 0)
    {
        return DICTIONARY_SIZE;
    }

    // return 0 if dictionary is not loaded
    else
        return 0;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    // creates a variable to go through the index
    int index = 0;

    // iterate through the HASH_TABLE array
    while (index < SIZE)
    {
        // go to the next index if HASH_TABLE is empty
        if (HASH_TABLE[index] == NULL)
        {
            index++;
        }

        // iterate through nodes and start freeing/ releasing if not empty
        else
        {
            while(HASH_TABLE[index] != NULL)
            {
                node* pointer = HASH_TABLE[index];
                HASH_TABLE[index] = pointer->next;
                free(pointer);
            }

            // continue to go through the index one at a time
            index++;
        }
    }

    // success
    return true;
}