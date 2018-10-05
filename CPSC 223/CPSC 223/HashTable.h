#ifndef HashTable_h
#define HashTable_h

#include <stdio.h>
#pragma warning(disable: 4996)

struct nlist;
typedef struct nlist nlist;
unsigned hash(char *s);
nlist *lookup(char *s);
char *strdup_ht(char *s);
nlist *install(char *name, char *defn);
void undef_(char *name);
void testHashTable();
int test_cpp();
#endif /*HashTable_h*/