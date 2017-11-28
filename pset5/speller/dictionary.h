/**
 * Declares a dictionary's functionality.
 */

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

// maximum length of a word is 45 characters long
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis [which is found in dictionaries/large])
#define LENGTH 45

// defining the custome data type struct which we have called 'node'.
typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
}
node;

// HASH_TABLE size
#define SIZE 1000000

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word);

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary);

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void);

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void);

#endif // DICTIONARY_H
