#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include "LongestLine.h"

#define MAXVAL 100
#define MAXLINE 1000
#define BUFSIZE 100
#define MAXOP 100
#define NUMBER '0';

int sp = 0;
double val[MAXVAL];

char buf[BUFSIZE];
int bufp = 0;

bool berror = false;
double store[26];

double atof_(char s[]) //string to double
{
	double val, power;
	int i, sign;

	for (i = 0; isspace(s[i]); i++)
	{
		;
	}

	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
	{
		i++;
	}

	for (val = 0.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0');
	}
	if (s[i] == '.')
	{
		i++;
	}
	if (s[i] == 'e' || s[i] == 'E')
	{
		i++;
		if (s[i] == '-')
		{
			//todo
		}
	}
	for (power = 1.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	return sign * val / power;
}

void testAtoF()
{
	double sum, atof_(char[]);
	char line[MAXLINE];
	int getline(char line[], int max);

	sum = 0;
	while (getline_(line, MAXLINE) > 0)
	{
		printf("\t%g\n", sum += atof_(line));
	}
}

void push(double f)
{
	if (sp < MAXVAL)
	{
		val[sp++] = f;
	}
	else
	{
		printf("error: stack full, can't push %g\n" ,f);
	}
}

double pop(void)
{
	if (sp > 0)
	{
		return val[--sp];
	}
	else
	{
		printf("error: stack empty\n");
		return 0.0;
	}
}

int getch_(void) //get a (possibly pushed back) character
{
	/*if (bufp != 0)
	{
		buf[--bufp];
	}
	else
	{
		bufp = 0;
		return getchar();
	}*/
	return (bufp > 0) ? buf[--bufp] : getchar();

}

void ungetch_(int c) //push character back on input
{
	if (bufp >= BUFSIZE)
	{
		printf("ungetch: too many characters\n");
	}
	else
	{
		buf[bufp++] = c;
	}
}

void ungets(char s[])
{
	if (bufp >= BUFSIZE)
	{
		printf("ungets: too many characters\n");
	}
	else
	{
		for (int i = 0; i < ((sizeof(s) / sizeof(char)) - 1); i++)
		{
			ungetch(s[i]);
		}
	}
}

int getop(char s[])
{
	int i, c;

	while ((s[0] = c = getch_()) == ' ' || c == '\t')
	{
		;
	}

	s[1] = '\0';
	if (!isdigit(c) && c != '.') //if not a number
	{
		return c;
	}
	i = 0;
	if (isdigit(c)) //collect integer part
	{
		while (isdigit(s[++i] = c = getch_()))
		{
			;
		}
	}
	if (c == '.') // collect fraction part
	{
		while (isdigit(s[++i] = c = getch_()))
		{
			;
		}
	}
	s[i] = '\0';
	if (c != EOF)
	{
		ungetch(c);
	}
	return NUMBER;
}

double add_(double op1, double op2)
{
	return op1 + op2;
}

double sub_(double op1, double op2)
{
	return op2 - op1;
}

double mult_(double op1, double op2)
{
	return op1 * op2;
}

double div_(double op1, double op2)
{
	if (op2 == 0)
	{
		printf("error: zero division not possible\n");
		berror = true;
	}
	else
	{
		return op1 / op2;
	}
}

double mod_(double op1, double op2)
{
	return (int)op2 % (int)op1;
}

double pow_(double op1, double op2)
{
	return pow(op1, op2);
}

double sin_(double op1)
{
	return sin(op1);
}

double cos_(double op1)
{
	return cos(op1);
}

double tan_(double op1)
{
	return tan(op1);
}

double log_(double op1)
{
	return log10(op1);
}

double ln_(double op1)
{
	return log(op1);
}

double calc1(double(*fp)(double))
{
	if (sp < 1)
	{
		printf("error: Insufficient arguments\n");
		berror = true;
		return 0;
	}
	else
	{
		double op1 = pop();
		double result = (*fp)(op1);
		return result;
	}
}

double calc(double(*fp)(double, double))
{
	if (sp < 2)
	{
		printf("error: Insufficient arguments\n");
		berror = true;
		return 0;
	}
	else
	{
		double op1 = pop();
		double op2 = pop();
		double result = (*fp)(op1, op2);
		return result;
	}
}

double peek()
{
	if (sp == 0)
	{
		return val[sp];
	}
	else
	{
		return val[sp - 1];
	}
}

int size()
{
	return sp;
}

void printStack()
{
	for (int i = sp - 1; i >= 0; i--)
	{
		printf("%d: %g\n", sp - 1 - i, val[i]);
	}
}

void swapTopTwo()
{
	double top1 = pop();
	double top2 = pop();
	push(top1);
	push(top2);
}

void duplicate()
{
	double top = pop();
	push(top);
	push(top);
}

void clearStack()
{
	for (int i = 0; i < sp; i++)
	{
		val[i] = 0;
	}
	sp = 0;
}

void pushIfResult(double result)
{
	if (!berror)
	{
		push(result);
		printf("Stack size: %d\n", size());
		printStack();
	}
	berror = false;
}

void reversePolishCalculator()
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF)
	{
		switch (type)
		{
		case '\n':
			break;
		case '0':
			pushIfResult(atof(s));
			break;
		case '+':
			pushIfResult(calc(add_));
			break;
		case '*':
			pushIfResult(calc(mult_));
			break;
		case '-':
			pushIfResult(calc(sub_));
			break;
		case '/':
			pushIfResult(calc(div_));
			break;
		case '%':
			pushIfResult(calc(mod_));
			break;
		case '$':
			printf("Top of the Stack: %g\n", peek());
			break;
		case '?':
			swapTopTwo();
			printf("Stack size: %d\n", size());
			printStack();
			break;
		case '<':
			clearStack();
			printf("Stack size: %d\n", size());
			printStack();
			break;
		case '#':
			return;
			break;
		case '&':
			duplicate();
			printf("Stack size: %d\n", size());
			printStack();
			break;
		case '^':
			pushIfResult(calc(pow_));
			break;
		case ']':
			pushIfResult(calc1(sin_));
			break;
		case '[':
			pushIfResult(calc1(cos_));
			break;
		case '|':
			pushIfResult(calc1(tan_));
			break;
		case '`':
			pushIfResult(calc1(log_));
			break;
		case '~':
			pushIfResult(calc1(ln_));
			break;
		case 'a':
			store[type - 'a'] = pop();
			printf("Stack size: %d\n", size());
			printStack;
			break;
		case 'b':
			store[type - 'a'] = pop();
			printf("Stack size: %d\n", size());
			printStack;
			break;
		case 'c':
			store[type - 'a'] = pop();
			printf("Stack size: %d\n", size());
			printStack;
			break;
		case 'd':
			store[type - 'a'] = pop();
			printf("Stack size: %d\n", size());
			printStack;
			break;
		case 'e':
			store[type - 'a'] = pop();
			printf("Stack size: %d\n", size());
			printStack;
			break;
		case 'f':
			store[type - 'a'] = pop();
			printf("Stack size: %d\n", size());
			printStack;
			break;
		case 'g':
			store[type - 'a'] = pop();
			printf("Stack size: %d\n", size());
			printStack;
			break;
		case 'h':
			store[type - 'a'] = pop();
			printf("Stack size: %d\n", size());
			printStack;
			break;
		case 'i':
			store[type - 'a'] = pop();
			printf("Stack size: %d\n", size());
			printStack;
			break;
		case 'j':
			store[type - 'a'] = pop();
			printf("Stack size: %d\n", size());
			printStack;
			break;
		case 'k':
			store[type - 'a'] = pop();
			printf("Stack size: %d\n", size());
			printStack;
			break;
		case 'l':
			store[type - 'a'] = pop();
			printf("Stack size: %d\n", size());
			printStack;
			break;
		case 'm':
			store[type - 'a'] = pop();
			printf("Stack size: %d\n", size());
			printStack;
			break;
		case 'n':
			store[type - 'a'] = pop();
			printf("Stack size: %d\n", size());
			printStack;
			break;
		case 'o':
			store[type - 'a'] = pop();
			printf("Stack size: %d\n", size());
			printStack;
			break;
		case 'p':
			store[type - 'a'] = pop();
			printf("Stack size: %d\n", size());
			printStack;
			break;
		case 'q':
			store[type - 'a'] = pop();
			printf("Stack size: %d\n", size());
			printStack;
			break;
		case 'r':
			store[type - 'a'] = pop();
			printf("Stack size: %d\n", size());
			printStack;
			break;
		case 's':
			store[type - 'a'] = pop();
			printf("Stack size: %d\n", size());
			printStack;
			break;
		case 't':
			store[type - 'a'] = pop();
			printf("Stack size: %d\n", size());
			printStack;
			break;
		case 'u':
			store[type - 'a'] = pop();
			printf("Stack size: %d\n", size());
			printStack;
			break;
		case 'v':
			store[type - 'a'] = pop();
			printf("Stack size: %d\n", size());
			printStack;
			break;
		case 'w':
			store[type - 'a'] = pop();
			printf("Stack size: %d\n", size());
			printStack;
			break;
		case 'x':
			store[type - 'a'] = pop();
			printf("Stack size: %d\n", size());
			printStack;
			break;
		case 'y':
			store[type - 'a'] = pop();
			printf("Stack size: %d\n", size());
			printStack;
			break;
		case 'z':
			store[type - 'a'] = pop();
			printf("Stack size: %d\n", size());
			printStack;
			break;
		case 'A': 
			push(store[type - 'A']);
			printStack();
			break;
		case 'B':
			push(store[type - 'A']);
			printStack();
			break;
		case 'C':
			push(store[type - 'A']);
			printStack();
			break;
		case 'D':
			push(store[type - 'A']);
			printStack();
			break;
		case 'E':
			push(store[type - 'A']);
			printStack();
			break;
		case 'F':
			push(store[type - 'A']);
			printStack();
			break;
		case 'G':
			push(store[type - 'A']);
			printStack();
			break;
		case 'H':
			push(store[type - 'A']);
			printStack();
			break;
		case 'I':
			push(store[type - 'A']);
			printStack();
			break;
		case 'J':
			push(store[type - 'A']);
			printStack();
			break;
		case 'K':
			push(store[type - 'A']);
			printStack();
			break;
		case 'L':
			push(store[type - 'A']);
			printStack();
			break;
		case 'M':
			push(store[type - 'A']);
			printStack();
			break;
		case 'N':
			push(store[type - 'A']);
			printStack();
			break;
		case 'O':
			push(store[type - 'A']);
			printStack();
			break;
		case 'P':
			push(store[type - 'A']);
			printStack();
			break;
		case 'Q':
			push(store[type - 'A']);
			printStack();
			break;
		case 'R':
			push(store[type - 'A']);
			printStack();
			break;
		case 'S':
			push(store[type - 'A']);
			printStack();
			break;
		case 'T':
			push(store[type - 'A']);
			printStack();
			break;
		case 'U':
			push(store[type - 'A']);
			printStack();
			break;
		case 'V':
			push(store[type - 'A']);
			printStack();
			break;
		case 'W':
			push(store[type - 'A']);
			printStack();
			break;
		case 'X':
			push(store[type - 'A']);
			printStack();
			break;
		case 'Y':
			push(store[type - 'A']);
			printStack();
			break;
		case 'Z':
			push(store[type - 'A']);
			printStack();
			break;
		default:
			printf("error: unknown command %s\n");
			break;
		}
	}
}