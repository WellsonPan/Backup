#ifndef CalcOperators_h
#define CalcOperators_h

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LongestLine.h"

double atof_(char s[]);
void testAtoF();
void push(double f);
double pop(void);
int getch_(void);
void ungetch_(int c);
int getop(char s[]);
void reversePolishCalculator();
void ungets(char s[]);

#endif /*CalcOperators_h*/
