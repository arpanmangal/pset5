#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "trie.h"


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
    return trie;
}

// Deleting a trie
void free_trie(struct letter* trie)
{
    free(trie);
}