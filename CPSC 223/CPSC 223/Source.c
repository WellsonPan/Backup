/*write a program that can read inputs and put them in length ordering, then alphabetical ordering
also with a word count
when printed out, its going to be printed out row by row
*///disregard this

//C:\Users\Wellson\documents\visual studio 2015\Projects\CPSC 223\Debug

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdarg.h>
#include "LongestLine.h"
#include "Operators.h"
#include "Bits.h"
#include "CalcOperators.h"
#include "Pointers.h"
#include "Struct.h"
#include "wlnode.h"
#include "HashTable.h"
/*write string functions: strcpy, strcat, strcmp, strncpy, strncpy, strlen, review bitwise operators, review stack, no (extern, register, goto)
there is going to be test functions for some*/
#define MAXLINE 1000
#define MAXLINES 5000
#define IN 1
#define OUT 0

int fun_with_bits()
{
	int n = 0256; //10101110;
	n = ~n; //01010001
	int mask = 0xFF; //11111111;
	int result = n & mask; // just the bottom three
	return result;
}

/*void controlToOctal(bool bOctal)
{
	int c;
	char buf[50];
	char* fmt[] = {"\\%03o", "\\%02x"};

	while ((c = getchar) != EOF)
	{
		if (iscntrl(c) || c == ' ')
		{
			sprintf(buf, fmt[bOctal ? 0 : 1], c);
		}
		else
		{
			sprintf(buf, "%c", c);
		}
	}
}*/

void minprintf(char *fmt, ...)
{
	va_list ap;
	char *p, *sval;
	int ival;
	double dval;
	char fmtbuf[20];

	va_start(ap, fmt);
	for (p = fmt; *p; p++)
	{
		if (*p != '%')
		{
			putchar(*p);
			continue;
		}

		char *pfmtbuf = fmtbuf;
		while (strchr("doxXfes", *p) == NULL)
		{
			*pfmtbuf++ = *p++;
		}
		*pfmtbuf++ = *p;
		*pfmtbuf = '\0';

		switch (*p)
		{
		case 'd':
			ival = va_arg(ap, int);
			printf(fmtbuf, ival);
			break;
		case 'o':
			ival = va_arg(ap, int);
			printf(fmtbuf, ival);
			break;
		case 'x':
			ival = va_arg(ap, int);
			printf(fmtbuf, ival);
			break;
		case 'X':
			ival = va_arg(ap, int);
			printf(fmtbuf, ival);
			break;
		case 'f':
			dval = va_arg(ap, double);
			printf(fmtbuf, dval);
			break;
		case 'e':
			dval = va_arg(ap, double);
			printf(fmtbuf, dval);
			break;
		case 's':
			sval = va_arg(ap, char*);
			printf(fmtbuf, sval);
			break;
		default:
			putchar(*p);
			break;
		}
	}
	va_end(ap);
}

void rudCalc()
{
	double sum, v;

	sum = 0;
	while (scanf("%lf", &v) == 1)
	{
		printf("\t%.2f\n", sum += v);
	}
}

void filecopy(FILE *ifp, FILE *ofp)
{
	int c;
	while ((c = getc(ifp)) != EOF)
	{
		putc(c, ofp);
	}
}

int cat(int argc, const char* argv[])
{
	FILE *fp;
	if (argc == 1)
	{
		filecopy(stdin, stdout);
	}
	else
	{
		while (--argc > 0)
		{
			if ((fp = fopen(*++argv, "r")) == NULL)
			{
				printf("cat: can't open %s\n", *argv);
				return 1;
			}
			else
			{
				filecopy(fp, stdout);
				fclose(fp);
			}
		}
	}
	return 0;
}

void cat2(int argc, char *argv[])
{
	FILE *fp;
	char *prog = argv[0];

	if (argc == 1)
	{
		filecopy(stdin, stdout);
	}
	else
	{
		while (--argc > 0)
		{
			if ((fp = fopen(*++argv, "r")) == NULL)
			{
				fprintf(stderr, "%s: can't open %s\n", prog, *argv);
				exit(1);
			}
			else
			{
				filecopy(fp, stdout);
				fclose(fp);
			}
		}
	}
	if (ferror(stdout))
	{
		fprintf(stderr, "%s: error writing stdout\n", prog);
		exit(2);
	}
	exit(0);
}

int main(int argc, char *argv[])
{
	for (int i = 0; i < argc; ++i)
	{
		//diff_(argc, &argv[argc]);
	}
	//cat2(argc, argv);

	//cat(argc, argv);

	//rudCalc();

	//minprintf("%-15.15o", 25);

	//test_cpp();
	//getchar();
	return 0;
}

/*int main(int argc, char *argv[])
{
	if (strcmp(argv[1], "upper") == 0 && argc == 2)
	{
		int c;

		while ((c = getchar()) != EOF)
		{
			putchar(toupper(c));
		}
	}
	else if (strcmp(argv[1], "lower") == 0 && argc == 2)
	{
		int c;

		while ((c = getchar()) != EOF)
		{
			putchar(tolower(c));
		}
	}
	else
	{
		printf("Put in just upper or lower next time");
	}

	//testHashTable();

	//test_wl();

	//buildTree();
	//searchTree(buildTree(), "men");
	//countCKeywords();

	getchar();
	return 0;
}*/
/*unsigned getNthBit(unsigned x, int p)
{
	unsigned y = 0x00000001;
	if ((x &= (y << p)) > 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	//return (x >> (p + 1 - n)) & ~(~0 << n);
}

unsigned flip_bit(unsigned x)
{
	return;
}

int stringLength(char *s)
{
	int i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return i;
}*/
/*
char *lineptr[MAXLINES];

int numcmp(char *s1, char *s2)
{
	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);

	if (v1 < v2)
	{
		return -1;
	}
	else if (v1 > v2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void swapper(void *v[], int i, int j)
{
	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void qsort_2(void *v[], int left, int right, int(*comp)(void *, void *))
{
	int i, last;
	//void swapper(void *v[], int, int);

	if (left >= right)
	{
		return;
	}
	swapper(v, left, (left + right)/2);
	last = left;
	for (i = left + 1; i <= right; i++)
	{
		if ((*comp)(v[i], v[left]) < 0)
		{
			swapper(v, ++last, i);
		}
	}
	swapper(v, left, last);
	qsort_2(v, left, last - 1, comp);
	qsort_2(v ,last + 1, right, comp);
}

int main(int argc, char * argv[]) //email to wmccarthy@fullerton.edu
{
	int nlines;
	int numeric = 0;
	int reverseOrder = 0;
	int fold = 0;

	if (argc > 1 && strcmp(argv[1], "-n") == 0)
	{
		numeric = 1;
	}

	if (argc > 1 && strcmp(argv[1], "-nr") == 0)
	{
		numeric = 1;
		reverseOrder = 1;
	}

	if (argc > 1 && strcmp(argv[1], "-r") == 0)
	{
		reverseOrder = 1;
	}

	if (argc > 1 && strcmp(argv[1], "-f") == 0)
	{
		fold = 1;
	}
	if (reverseOrder == 0 && (nlines = readlines(lineptr, MAXLINES)) >= 0)
	{
		if (fold == 1)
		{
			for (int i = 0; i < sizeof(lineptr) / sizeof(char*); i++)
			{
				lineptr[i] = tolower(lineptr[i]);
			}
		}
		qsort_2((void **) lineptr, 0, nlines - 1, (int (*)(void*, void*))(numeric ? numcmp : strcmp));
		writelines(lineptr, nlines);
		return 0;
	}
	else if (reverseOrder == 1 && (nlines = readlines(lineptr, MAXLINES)) >= 0)
	{
		if (fold == 1)
		{
			for (int i = 0; i < sizeof(lineptr) / sizeof(char*); i++)
			{
				lineptr[i] = tolower(lineptr[i]);
			}
		}
		qsort_2((void **)lineptr, 0, nlines - 1, (int(*)(void*, void*))(numeric ? numcmp : strcmp));
		writelines(lineptr, nlines);
		return 0;
	}
	else
	{
		printf("input too big to sort\n");
		return 1;
	}
	*/
	/*
	char line[MAXLINE];
	long lineno = 0;
	int c, except = 0, number = 0, found = 0;

	while (--argc > 0 && (*++argv)[0] == '-')
	{
		while (c = *++argv[0])
		{
			switch (c)
			{
			case 'x':
				except = 1;
				break;
			case 'n':
				number = 1;
				break;
			default:
				printf("find: illegal option %c\n", c);
				argc = 0;
				found = -1;
				break;
			}
		}
	}
	if (argc != 1)
	{
		printf("Usage: find -x -n pattern\n");
	}
	else
	{
		while (getline_(line, MAXLINE) > 0) //change in c and h files
		{
			lineno++;
			if ((strstr(line, *argv) != NULL) != except)
			{
				if (number)
				{
					printf("%ld:", lineno);
				}
				//printf("%s", **argv);
				printf("%s\n", line);
				found++;
			}
		}
	}*/
	//printf("program name is: %s\n", argv[0]);

	/*if (argc != 2)
	{
		printf("Usage: %s", argv[0]);
	}

	for (int i = 1; i < argc; i++)
	{
		printf("%s%s", argv[i], (i < argv[i] ? " " : ""));
	}
	printf("\n");*/

	//testMulti();
	//testReadWriteLines(); //still doesn't work
	//testStrCopy_();
	//testAlloc();
	//strlenTest();
	//testGetInt();
	//testSwap();

	//testFibFact();

	//testAtoF();
	//reversePolishCalculator();

	//testBinSearch();
	//testAtoI(); still doesn't work
	//testShellsort();
	//testReverseStringInPlace();
	//testExpand();
	//testItoA(10);
	//testItoABase(12);

	//test_getbits(0x0000ffff, 9, 28, 15);
	//test_setbits(0x12345678, 7, 31, 4, 8, 0x000000ab);
	//test_invert(0xaaaaaaaa, 7, 32, 4, 8);
	//test_rightrot(0x0abc0def, 4, 28, 4);
	//test_leftrot(0x0abc0def, 4, 28, 4);

	//char buf[33];
	//int i = 0;
	//convertToBaseTwoBackwards(19);
	//to_binary_re(13, &i, buf);
	//printf("%s\n", buf);


	//Excersice 1-19
	/*char lines[] = {"Tab	Tab	Tab	"};
	detab(lines);
	printf("%s\n", lines);*/

	//bitwise operators
	/*& bitwise AND	110 & 011 ==> 010
	| bitwise OR	110 | 011 ==> 111
	^ bitwise XOR	110 ^ 011 ==> 101
	<< left shift	00000 110 << 3 ==> 00 110 000 //space is not actually included
	>> right shift	00000 110 >> 3 ==> 00 000 000 //unsigned
	>> right shift  11110 110 >> 3 ==> 11 111 110
	~ one's complement	~011 ==> 100*/

	//printf("result is: %d\n", fun_with_bits());

	//concatenate and squeeze functions

	/*for (char c = 'a'; c <= 'z'; c++)
	{
		testSqueeze(c);
	}

	char s[50] = "Tom Brady is really ";
	char t[] = "fill in the blank here";
	strcat_(s, t);
	printf("%s\n", s);*/

	//print longest line//

	/*int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((len = getline_(line, MAXLINE)) > 0)
	{
		if (len > max)
		{
			max = len;
			copy(longest, line);
		}
	}
	if (max > 0)
	{
		printf("%s\n", longest);
	}*/

	//Reverse Every Line

	/*int len;
	char line[MAXLINE];

	while ((len = getline_(line, MAXLINE)) > 0)
	{
		reverse(line);
		printf("%3d : %s\n", len, line);
	}*/

	//counts the lines, words, and characters in the input

	/*long nc = 0, newlines = 0, tabs = 0, spaces = 0, words = 0;
	int c = 0, state = OUT;
	while ((c = getchar()) != EOF)
	{
		nc++;
		if (c == '\n')
		{
			newlines++;
		}
		if (c == '\t' || c == '\n' || c == ' ')
		{
			state = OUT;
		}
		else if (state == OUT)
		{
			state = IN;
			words++;
		}

		switch (c)
		{
			case '\n':
			{
				newlines++;
				break;
			}
			case '\t':
			{
				tabs++;
			}
			case ' ':
			{
				spaces++;
			}
			default:
			{
				nc++;
			}
		}
		putchar(c);
	}
	printf("You entered %ld character(s)\n", nc);
	printf("There were %ld newline(s) and %ld word(s)\n", newlines, words);*/

	//count digits, whitespaces, and others

	/*int c, nwhite = 0, nother = 0;
	int ndigit[10];

	for (int i = 0; i < 10; i++)
	{
		ndigit[i] = 0;
	}

	while ((c = getchar()) != EOF)
	{
		if (c >= '0' && c <= '9')
		{
			ndigit[c - '0']++;
		}
		else if (c == ' ' || c == '\t' || c == '\n')
		{
			nwhite++;
		}
		else
		{
			nother++;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		printf("%c's : %d\n", i + '0', ndigit[i]);
	}
	printf("White Spaces: %d\nOther: %d\n", nwhite, nother);*/

	//printf("...program finished\n");
		//getchar();
	//printf("%d", found);
		//return found;
		//return 0;
	//}