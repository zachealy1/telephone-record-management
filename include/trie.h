#ifndef TRIE_H
#define TRIE_H
#include <stdio.h>

typedef struct trie_node {
    struct trie_node *children[10];
    bool is_end;
} trie_node_t;

void trie_insert(trie_node_t *root,
                 unsigned short country_code,
                 unsigned long long phone_number);

bool trie_search(const trie_node_t *root,
                 unsigned short country_code,
                 unsigned long long phone_number);

void trie_free(trie_node_t *root);

#endif
