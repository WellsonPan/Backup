#ifndef Operators_h
#define Operators_h

#include <stdio.h>

void squeeze(char s[], int c);
void squeeze_ptr(char *s, int c);
void testSqueeze(char c);
void strcat_(char s[], char t[]);
void strcat_ptr(char *s, char *t);
void convertToBaseTwoBackwards(int num);
//int decimalToBinary(int n);
void to_binary(unsigned x, char buf[]);
void to_binary_re(unsigned x, int* pi, char buf[]);
int binSearch(int x, int v[], int n);
void testBinSearch();
int atoi_(char s[]);
//void testAtoI();
void shellsort(int v[], int n);
void testShellsort();
void reverseStringInPlace(char s[]);
void testReverseStringInPlace();
void expand(char s1[], char s2[]);
void testExpand();
void itoa_(int n, char s[], int minWidth);
void testItoA(int minWidth);
void itoaBase(int n, char s[], int base);
void testItoABase(int base);
double fib(int n);
double fibRec(int n);
double fact(int n);
double factRec(int n);
void testFibFact();

#endif
