#include "../include/trie.h"
#include <stdlib.h>

void trie_insert(trie_node_t *root,
                 const unsigned short country_code,
                 const unsigned long long phone_number) {
    char key[20];
    snprintf(key, sizeof(key), "%03hu%llu", country_code, phone_number);

    trie_node_t *node = root;
    for (const char *p = key; *p; ++p) {
        const int d = *p - '0';
        if (node->children[d] == NULL) {
            trie_node_t *new_node = calloc(1, sizeof *new_node);
            if (!new_node) return;
            node->children[d] = new_node;
        }
        node = node->children[d];
    }
    node->is_end = true;
}

bool trie_search(const trie_node_t *root,
                        const unsigned short country_code,
                        const unsigned long long phone_number) {
    char key[20];
    snprintf(key, sizeof(key), "%03hu%llu", country_code, phone_number);

    const trie_node_t *node = root;
    for (char *p = key; *p; ++p) {
        int d = *p - '0';
        if (!node->children[d]) {
            return false;
        }
        node = node->children[d];
    }
    return node->is_end;
}
