#ifndef TRIE_H
#define TRIE_H

typedef struct trie_node {
    struct trie_node *children[10];
    bool is_end;
} trie_node_t;

#endif
