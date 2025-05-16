#include "../include/trie.h"

#include <stdio.h>
#include <stdlib.h>

/*
 * trie_insert
 *
 * Insert a full phone number (including country code) into the trie.
 *
 * Parameters:
 *   root         – pointer to the root node of the trie; must be initialised
 *                   (all children NULL, is_end = false)
 *   country_code – three-digit international dialling code (e.g. 044 for UK)
 *   phone_number – local phone number to insert
 */
void trie_insert(trie_node_t *root,
                 const unsigned short country_code,
                 const unsigned long long phone_number) {
    /* Combine country code and phone number into a digit string */
    char key[20];
    snprintf(key, sizeof(key), "%03hu%llu", country_code, phone_number);

    trie_node_t *node = root;
    /* Traverse each character (digit) in the key */
    for (const char *p = key; *p; ++p) {
        const int d = *p - '0';  /* Convert character to index 0–9 */
        if (node->children[d] == NULL) {
            /* Allocate a new node if this path does not yet exist */
            trie_node_t *new_node = calloc(1, sizeof *new_node);
            if (!new_node) {
                /* Allocation failed – exit early (no insertion) */
                return;
            }
            node->children[d] = new_node;
        }
        node = node->children[d];
    }
    /* Mark the end of the number in the trie */
    node->is_end = true;
}

/*
 * trie_search
 *
 * Search for the presence of a phone number (with country code) in the trie.
 *
 * Parameters:
 *   root         – pointer to the root node of the trie
 *   country_code – three-digit international dialling code
 *   phone_number – local phone number to search for
 *
 * Returns:
 *   true  if the exact sequence of digits exists and the final node
 *         is marked as the end of an entry;
 *   false otherwise.
 */
bool trie_search(const trie_node_t *root,
                 const unsigned short country_code,
                 const unsigned long long phone_number) {
    /* Build the digit string to match the insertion format */
    char key[32];
    snprintf(key, sizeof(key), "%03hu%llu", country_code, phone_number);

    const trie_node_t *node = root;
    /* Walk the trie following each digit */
    for (const char *p = key; *p; ++p) {
        /* Reject any non-digit, though snprintf ensures digits only */
        if (*p < '0' || *p > '9') {
            return false;
        }
        const int d = *p - '0';
        if (!node->children[d]) {
            /* If a branch is missing, number is not registered */
            return false;
        }
        node = node->children[d];
    }
    /* Only return true if the final node marks the end of a complete entry */
    return node->is_end;
}

/*
 * trie_free
 *
 * Recursively free all nodes in the trie, releasing allocated memory.
 *
 * Parameters:
 *   root – pointer to the root node of the trie; after this, the trie
 *           must not be accessed again.
 */
void trie_free(trie_node_t *root) {
    /* Recursively free each child subtree */
    for (int i = 0; i < 10; i++) {
        if (root->children[i] != NULL) {
            trie_free(root->children[i]);
        }
    }
    /* Free this node */
    free(root);
}
