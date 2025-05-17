# Phone Directory CLI

A simple command-line application in C for loading, querying and analysing a phone-record database. Records are read from a text file, then you can:

- Determine which country code has the most entries
- Check whether a given number is already registered (linear search and trie-based lookup)
- Insert and search numbers efficiently using a digit trie

---

## Features

- **File I/O**  
  Load records from a user-specified text file into a dynamically allocated array.

- **Analysis**  
  Find the country code with the highest number of records.

- **Linear Search**  
  Check for existence of a specific phone number by scanning the array.

- **Trie-Based Lookup**  
  Build a digit trie of country code + phone number for fast insert/search.

- **Memory Management**  
  Clean up all allocated memory (records, names, trie) on exit.

---

## Prerequisites

- A C compiler (e.g. `gcc`)
- Standard C library headers (`stdio.h`, `stdlib.h`, `string.h`, `stdbool.h`)

---
