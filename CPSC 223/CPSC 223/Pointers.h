#ifndef Pointers_h
#define Pointers_h

#include <stdio.h>

void swap_(int *p, int *q);
void testSwap();
int getint(int *pn);
void testGetInt();
int strlen_(char *ps);
void strlenTest();
char * alloc_(int n);
void afree(char *p);
char * allocHelper(int n, char marker);
void testAlloc();
//void strcopy_(char *ps, char *pt, int n);
void strcopy_(char *ps, char *pt);
void testStrCopy_();
int testReadWriteLines();
int testMulti();
int readlines(char * lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);

#endif /*end of Pointers_h*/
