
// implementation of trie data structure as suggested in the walkthrough
typedef struct letter
{
    int is_word;
    struct letter* arr[27];
}letter;

letter *root;

// fuctions
struct letter* create_trie();
void free_trie(struct letter* trie);