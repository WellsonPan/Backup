#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "Pointers.h"
#include "LongestLine.h"

#define RUNNING_TEST {printf("\n============== TESTING: "); printf(__FUNCTION__); printf(" ... ===================\n");}
#define ENDING_TEST {printf("\n============== FINISHED TESTING: "); printf(__FUNCTION__); printf(" ... ===================\n");}

#define ALLOCSIZE 10000
#define MAXLINES 5000
#define MAXLEN 1000
static char allocbuf[ALLOCSIZE];
static char * allocp = allocbuf;

char *lineptr[MAXLINES];

void swap_(int *p, int *q)
{
	int temp = *p;
	*p = *q;
	*q = temp;
}

void testSwap()
{
	int x = 10, y = 20;
	printf("Before swap: x = %d, y = %d\n", x, y);
	swap_(&x, &y);
	printf("After swap: x = %d, y = %d\n", x, y);
}

int getch_(void);
void ungetch_(int);

int getint(int *pn)
{
	int c, sign;

	while (isspace(c = getch()))
	{
		;
	}
	if (!isdigit(c) && c != EOF && c != '+' &&  c != '-')
	{
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
	{
		c = getch();
	}
	if (!isdigit(c))
	{
		ungetch(c);
		return c;
	}
	for (*pn = 0; isdigit(c); c = getch())
	{
		*pn = 10 * *pn + (c - '0');
	}
	*pn *= sign;
	if (c != EOF)
	{
		ungetch(c);
	}
	return c;
}

void testGetInt()
{
	RUNNING_TEST
	int x;
	getint(&x);
	printf("x was: %d\n", x);

	int values[5];
	int size = sizeof(values) / sizeof(int);

	for (int i = 0; i < size; i++)
	{
		int y;
		getint(&y);
		values[i] = y;
	}

	for (int i = 0; i < size; i++)
	{
		printf("%d\n", values[i]);
	}

	ENDING_TEST
}

int strlen_(char *ps)
{
	int len = 0;

	for (len = 0; *ps != '\0'; ++ps)
	{
		len++;
	}

	return len;
}

void strlenTest()
{
	RUNNING_TEST

	char * strings[] = {"Words", "", " ", "More Words", "Even More Words", "Last Word"};
	for (int i = 0; i < sizeof(strings) / sizeof(char*); i++)
	{
		printf("strlen_(\'%s\') = %d\n", strings[i], strlen_(strings[i]));
	}
	/*char name[] = "";
	char blank[] = " ";
	char ordString[] = "Hello World!";
	printf("strlen_(\'%s\') = %d\n", name, strlen_(name));
	printf("strlen_(\'%s\') = %d\n", blank, strlen_(blank));

	char * p = &ordString[0];
	for (int i = 0; i < sizeof(ordString) / sizeof(char); i++)
	{
		printf("strlen_(\'%s\') = %d\n", p + i, strlen_(p + i));
	}

	while (*p)
	{
		printf("strlen_(\'%s\') = %d\n", p, strlen_(p));
		p++;
	}
	*/
	ENDING_TEST
}

char * alloc_(int n)
{
	if (allocbuf + ALLOCSIZE - allocp >= n)
	{
		allocp += n;
		return allocp - n;
	}
	else
	{
		return 0;
	}
}

void afree(char *p)
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
	{
		allocp = p;
	}
}

char * allocHelper(int n, char marker)
{
	int size = n;
	char *p = alloc_(size);
	if (p == 0)
	{
		printf("Insufficient memory available for: %d chars", size);
		return -1;
	}
	memset(p, marker, sizeof(char) * (size - 1));
	for (int i = 0; i < 100; i += 100)
	{
		p[i] = '\n';
	}
	p[size - 1] = '\0';
	//printf("p (%d bytes) is: %s\n", size, p);

	return p;
}

void testAlloc()
{
	RUNNING_TEST

		char * buffers[20];
	int i = 0;

	buffers[i++] = allocHelper(50, 'x');
	printf("buffers[%d] = %s\n", 0, buffers[0]);

	buffers[i++] = allocHelper(200, 'y');
	printf("buffers[%d] = %s\n", 1, buffers[1]);

	buffers[i++] = allocHelper(400, '&');
	printf("buffers[%d] = %s\n", 2, buffers[2]);

	afree(buffers[2]); //have to free with lifo
	memset(buffers[2], '\0', 400);
	buffers[2] = NULL;
	printf("buffers[%d] = %s\n", 2, buffers[2]);

	ENDING_TEST
}

void strcopy_(char *ps, char *pt)//, int n) //destination is ps, source is pt
{
	int i = 0;
	//char *pstart = ps;
	//char *ptstart = pt;
	while ((*ps++ = *pt++) != '\0') {
		i++;
	}
	/*while (i < n && (*ps++ = *pt++) != '\0'){
		i++;
	}
	if (i == n)
	{
		pstart[n - 1] = '\0';
	}*/
}

void testStrCopy_()
{
	RUNNING_TEST

	char dest[6];
	char src[] = "avada kadavra";

	int size = sizeof(dest) / sizeof(char);

	strcopy_(dest, src, size);
	printf("dest is: \'%s\' and src is: \'%s\'", dest, src);

	ENDING_TEST
}

int readlines(char * lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = getline_(line, MAXLEN)) > 0)
	{
		if (nlines >= maxlines || (p = alloc_(len)) == NULL)
		{
			return -1;
		}
		else
		{
			line[len - 1] = '\0';
			line[len] = '\0';
			strcopy_(p, line);
			lineptr[nlines++] = p;
		}
	}

	return nlines;
}

/*void writelines(char *lineptr[], int nlines)
{
	int i;
	//printf("%d\n", nlines);
	for (i = 0; i < nlines; i++)
	{
		printf("%s\n", lineptr[i]);
	}
}*/

void writelines(char *lineptr[], int nlines)
{
	while (nlines-- > 0)
	{
		printf("%s\n", *lineptr++);
	}
}

void qsort_(char *v[], int left, int right)
{
	int i, last;
	void swap__(char *v[], int i, int j);

	if (left >= right)
	{
		return;
	}
	swap__(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++)
	{
		if (strcmp(v[i], v[left]) < 0)
		{
			swap__(v, ++last, i);
		}
	}
	swap__(v, left, last);
	qsort_(v, left, last - 1);
	qsort_(v, last + 1, right);
}

void swap__(char *v[], int i, int j)
{
	char *temp;
	temp = v[j];
	v[i] = v[j];
	v[j] = temp;
}

int testReadWriteLines()
{
	int nlines;

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
	{
		printf("\n===>BEGINNING qsort...");
		qsort_(lineptr, 0, nlines - 1);
		printf("\n===> sort completed\n\n");
		writelines(lineptr, nlines);
		return 0;
	}
	else
	{
		printf("error: input too big to sort\n");
		return 1;
	}
}

void multiHelper(void *pv, int rows, int cols)
{
	int *p = (int*)pv;
	int cells = rows * cols;
	while (cells-- > 0)
	{
		printf("%d ", *p++);
	}
}

int testMulti()
{
	RUNNING_TEST

		int numbers[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", numbers[i][j]);
		}
	}

	printf("\n\nNow testing with ust a pointer...\n");
	multiHelper((void*)numbers, 3, 3);
	ENDING_TEST
		return 0;
}