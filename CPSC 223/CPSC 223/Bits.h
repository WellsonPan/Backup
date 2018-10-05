#ifndef Bits_h
#define Bits_h

#include <stdio.h>

unsigned rightrot(unsigned x, int n);
void test_rightrot(unsigned x, int n, int max, int step);
unsigned leftrot(unsigned x, int n);
void test_leftrot(unsigned x, int n , int max, int step);
unsigned getbits(unsigned x, int p, int n);
unsigned flipBits(unsigned x);
unsigned flipEveryOtherBit(unsigned x);
unsigned setbits(unsigned x, int p, int n, unsigned y);
void test_getbits(unsigned x, int min, int max, int n);
void test_setbits(unsigned x, int p, int max, int step, int n, unsigned y);
unsigned invert(unsigned x, int p, int n);
void test_invert(unsigned x, int p, int max, int step, int n);

#endif /*Bits_h*/
