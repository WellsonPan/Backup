#ifndef wlnode_h
#define wlnode_h

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "Pointers.h"
#include "CalcOperators.h"
#pragma warning(disable: 4996)

#define MAXWORD 100

struct wlnode;
typedef struct wlnode wlnode;
wlnode* wlalloc();
char* strdup_wl(char *s);
int getword_wl(char *word, int lim);
wlnode* addtree_wl(wlnode* p, char *w, int lineno);
void shellsort_wl(wlnode* v[], int n);
void test_wl();

#endif /*wlnode_h*/
