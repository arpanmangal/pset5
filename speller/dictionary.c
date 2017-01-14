/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>

#include "dictionary.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>


// implementation of trie data structure as suggested in the walkthrough
//struct letter;
struct letter
{
    int is_word;
    struct letter* arr[27];
};


// Creating a trie
struct letter* create_trie()
{
    struct letter* trie = (struct letter*) malloc(sizeof(struct letter));
    
    // initialises all pointers
    int i;
    for(i = 0; i < 27; i++)
    {
        trie->arr[i] = NULL;
    }
    trie->is_word = 0;
    return trie;
}



// Deleting a trie
void free_trie(struct letter* trie)
{
    free(trie);
}



// begining of structure
struct letter *root = NULL;

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
    struct letter* cursor = root;
    
    int index;
    for(index = 0; word[index] != '\0'; index++)
    {
        // make case insensitive
        char lettr = tolower(word[index]);
        int i = (lettr == '\'') ? 26 : lettr - 'a';
        
        // if the word ends
        if (word[index + 1] == '\0')
        {
            if (cursor->arr[i] != NULL && cursor->arr[i]->is_word == 1)
            {
                return true;
            }
            return false;
        }
        
        // no further letters in the structure
        if (cursor->arr[i] == NULL)
        {
            return false;
        }
        
        // check next letter
        cursor = cursor->arr[i];
    }
    return false;
}

int num_of_words = 0;

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
    
    root = create_trie();
    char word[LENGTH + 1];
    while (fscanf(fp, "%s", word) != EOF)
    {
        num_of_words++;
        add_word(root, word);
    }
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return num_of_words;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool delete_trie(struct letter* Letter)
{
    // check the existence of Letter struct
    if (Letter == NULL)
    {
        return false;
    }
    
    // recursive step
    int i;
    for (i = 0; i < 27; i++)
    {
        if (Letter->arr[i] != NULL)
        {
            delete_trie(Letter->arr[i]);
            Letter->arr[i] = NULL;
        }
    }
    
    // termination step
    free_trie(Letter);
    Letter = NULL;
    return true;
}

bool unload(void)
{
    return delete_trie(root);
}
