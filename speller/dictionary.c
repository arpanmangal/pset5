/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>

#include "dictionary.h"
#include "trie.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * Adds the word in the dictionary structure using recursion
 */
void add_word(struct letter* Letter, char* word)
{
    int lettr = (word[0] == '\'') ? 26 : word[0] - 'a';
    
    // check if next trie exists
    if (Letter->arr[lettr] == NULL)
    {
        Letter->arr[lettr] = create_trie();
    }
    
    // check if word is ended (termination condition)
    if (word[1] == '\0')
    {
        Letter->arr[lettr]->is_word = 1;
        return;
    }
    
    // recursive condition
    add_word(Letter->arr[lettr], word + 1);
    return;
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    // TODO
    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    // try to open dictionary
    FILE *fp = fopen(dictionary, "r");
    if (fp == NULL)
    {
        // could not open dictionary
        return false;
    }
    
    struct letter *root = create_trie();
    char word[LENGTH + 1];
    while (fscanf(fp, "%s", word) != EOF)
    {
        add_word(root, word);
    }
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return 0;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    return false;
}
