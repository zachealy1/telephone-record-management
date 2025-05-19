#ifndef TRIE_H
#define TRIE_H

/*
 * trie_node_t
 *
 * Digit-based trie node for storing phone numbers.
 *
 * children: pointers for digits 0–9; NULL if no branch for that digit.
 * is_end:   flag indicating whether this node marks the end of a complete
 *           phone number entry.
 */
typedef struct trie_node {
    struct trie_node *children[10];
    bool is_end;
} trie_node_t;

/*
 * trie_insert
 *
 * Insert a full phone number (including country code) into the trie.
 *
 * Parameters:
 *   root         – pointer to the root node of the trie; must be initialised
 *                   (all children NULL, is_end = false)
 *   country_code – three-digit international dialling code
 *   phone_number – local phone number to insert
 */
void trie_insert(trie_node_t *root,
                 unsigned short country_code,
                 unsigned long long phone_number);

/*
 * trie_search
 *
 * Search for the existence of a phone number (with country code) in the trie.
 *
 * Parameters:
 *   root         - pointer to the root of the trie.
 *   country_code - international dialling code to search for.
 *   phone_number - local phone number digits to search for.
 */
bool trie_search(const trie_node_t *root,
                 unsigned short country_code,
                 unsigned long long phone_number);

/*
 * trie_free
 *
 * Recursively free all nodes in the trie to release allocated memory.
 *
 * Parameters:
 *   root - pointer to the root of the trie. After calling, the trie must not
 *          be accessed again.
 */
void trie_free(trie_node_t *root);

#endif  /* TRIE_H */
