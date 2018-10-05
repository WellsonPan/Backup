#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "Operators.h"
#include "LongestLine.h"
#include <limits.h>

//Squeeze function pg. 47

void squeeze(char s[], int c)
{
	int i, j;

	for (i = j = 0; s[i] != '\0'; i++)
	{
		if (s[i] != c)
		{
			s[j++] = s[i];
		}
	}
	s[j] = '\0';
}

void squeeze_ptr(char *s, int c)
{
	char *pt = s;
	while (*s != '\0')
	{
		if (*s != c)
		{
			*pt++ = *s;
		}
		s++;
	}
	*pt = '\0';
}

void testSqueeze(char c)
{
	char s[] = "I can't believe the Falcons lost yesterday!";
	squeeze(s, c);
	printf("removing %c: %s\n", c, s);
}

void strcat_(char s[], char t[])
{
	int i, j;

	i = j = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	while ((s[i++] = t[j++]) != '\0')
	{

	}
}

void strcat_ptr(char *s, char *t)
{
	while (*s++ != '\0')
	{

	}
	while ((*s++ = *t++) != '\0')
	{

	}
}

void convertToBaseTwoBackwards(int num)
{
	if (num == 0 || num == 1)
	{
		printf("%d", num);
	}
	else
	{
		printf("%d", (num%2));
		convertToBaseTwoBackwards(num/2);
	}
}

/*int decimalToBinary(int n) {
	int remainder;
	int binary = 0, i = 1;

	while (n != 0) {
		remainder = n % 2;
		n = n / 2;
		binary = binary + (remainder*i);
		i = i * 10;
	}
	return binary;
}*/

void to_binary(unsigned x, char buf[])
{
	int i = 0;
	while (x > 0)
	{
		buf[i++] = (x % 2) + '0';
		x >>= 1;
	}
	buf[i] = '\0';
	reverse(buf);
}

void to_binary_re(unsigned x, int* pi, char buf[]) 
{
	if (x == 0)
	{ 
		return; 
	}
	to_binary_re(x / 2, pi, buf);
	buf[(*pi)++] = x % 2 + '0';
}

int binSearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (x < v[mid])
		{
			high = mid - 1;
		}
		else if (x > v[mid])
		{
			low = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

void testBinSearch()
{
	int values[] = {1, 4, 9, 16, 25, 36, 49, 64, 81, 100};
	for (int i = 1; i < 100; i *= 2)
	{
		printf("searching for: %d -- search index is: %d\n", i, binSearch(i, values, sizeof(values) / sizeof(int)));
	}
}

int atoi_(char s[])
{
	int i = 0, n = 0, sign = 1;

	for (i = 0; isspace(s[i]); i++)
	{

	}

	bool neg = false;
	bool pos = false;
	while (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
		{
			neg = true;
		}
		else if (s[i] == '+')
		{
			pos = true;
		}
		if (neg && pos)
		{
			return 0;
		}
		sign *= (s[i] == '-' ? -1 : 1);
		i++;
	}

	//sign = (s[i] == '-' ? -1 : 1);
	//if ((s[i] == '+' || s[i] == '-'))
	//{
	//	i++;
	//}

	for (n = 0; isdigit(s[i]); i++)
	{
		n = 10 * n + (s[i] = '0');
	}
	return sign * n;
}

/*void testAtoI()
{
	 const char* num[] = {"7", "-3", "--4", "+=8", "---5", "+++++8"};

	for (int i = 0; i < 6; i++)
	{
		printf("atoi(%d) is: &d\n", num[i], atoi_(*num));
	}
}*/

void shellsort(int v[], int n)
{
	int gap, i, j, temp;

	for (gap = n / 2; gap > 0; gap /=2)
	{
		for (i = gap; i < n; i++)
		{
			for (j = i - gap; j >= 0 && (v[j] > v[j + gap]); j -= gap)
			{
				temp = v[j];
				v[j] = v[j + gap];
				v[j + gap] = temp;
			}
		}
	}
}

void testShellsort()
{
	int numbers[] = {6, 2, 6, 3, 7, 3, 3, 1, 6, 7};
	int bignumbers[1000];
	for (int i = 0; i < 100; i++)
	{
		int size = sizeof(numbers) / sizeof(int);
		memcpy(bignumbers + 10 * i, numbers, size * sizeof(int));
	}
	printf("==========================before the shellshort======================\n");
	for (int i = 0; i < 1000; i++)
	{
		printf("%d", bignumbers[i]);
	}

	shellsort(bignumbers, sizeof(bignumbers) / sizeof(int));

	printf("\n=========================after the shellsort=========================\n");
	for (int i = 0; i < 1000; i++)
	{
		printf("%d", bignumbers[i]);
	}
}

void reverseStringInPlace(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void testReverseStringInPlace()
{
	char names[] = "Sean Connery";

	printf("name before is: %s\n", names);
	reverse(names);
	printf("name after is: %s\n", names);
}

void expand(char s1[], char s2[])
{
	int begin = s1[0];
	int end = s1[strlen(s1) - 1];
	int length = end - begin;
	int i;

	for (i = 0; i <= length; i++)
	{
		s2[i] = begin + i;
	}
	s2[i] = '\0';
}

void testExpand()
{
	char buffer[250];
	memset(buffer, '\0', sizeof(buffer) / sizeof(char));

	expand("a-z", buffer);
	printf("a - z expanded into buffer gives... \n\t%s\n", buffer);

	expand("0-9", buffer);
	printf("0 - 9 expanded into buffer gives... \n\t%s\n", buffer);

	expand("A-Z", buffer);
	printf("A - Z expanded into buffer gives... \n\t%s\n", buffer);
}

void itoa_(int n, char s[], int minWidth)
{
	int i;
	bool isNeg = (n < 0);
	bool isIntMin = (n == INT_MIN);

	if (n == INT_MIN)
	{
		n += 1;
	}
	n = abs(n);


	i = 0;
	do
	{
		int remainder = n % 10;
		s[i++] = ( i == 0 && isIntMin ? remainder + 1 : remainder)+ '0';
	} 
	while ((n /= 10) > 0);

	if (isNeg)
	{
		s[i++] = '-';
	}
	while (i < minWidth)
	{
		s[i++] = ' ';
	}
	s[i] = '\0';
	reverse(s);
}

void testItoA(int minWidth)
{
	const int values[] = {123, -22, +22, -55, -76, +67, -67, 656, INT_MIN};
	char buf[256];

	for (int i = 0; i < sizeof(values) / sizeof(int); i++)
	{
		itoa(values[i], buf, minWidth);
		printf("itoa(%d) is: %s\n", values[i], buf);
	}
}

void itoaBase(int n, char s[], int base)
{
	int i;
	bool isNeg = (n < 0);
	bool isIntMin = (n == INT_MIN);
	char baseConvert[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	if (n == INT_MIN)
	{
		n += 1;
	}
	n = abs(n);
	i = 0;
	do
	{
		int remainder = n % base;
		int index = (i == 0 && isIntMin ? remainder + 1 : remainder);
		s[i++] = baseConvert[index];
	} while ((n /= base) > 0);

	if (isNeg)
	{
		s[i++] = '-';
	}
	s[i] = '\0';
	reverse(s);
}

void testItoABase(int base)
{
	const int values[] = { 123, -22, +22, -55, -76, +67, -67, 656, INT_MIN};
	char buf[256];

	for (int i = 0; i < sizeof(values) / sizeof(int); i++)
	{
		itoaBase(values[i], buf, base);
		printf("itoa(%d) is: %s\n", values[i], buf);
	}
}

double fib(int n)
{
	static double fibos[100];
	static bool init = false;
	static int size = sizeof(fibos) / sizeof(double);
	for (int i = 0; i < size; i++)
	{
		if (i == 0 || i == 1)
		{
			fibos[i] = 1.0;
		}
		else
		{
			fibos[i] = (fibos[i - 1] + fibos[i - 2]);
		}
		init = true;
	}
	return fibos[n];
}

double fibRec(int n)
{
	if (n == 0 || n == 1)
	{
		return 1;
	}
	else
	{
		return fibRec(n - 1) + fibRec(n - 2);
	}
}

double fact(int n)
{
	double result = 1.0;
	while (n > 1)
	{
		result *= n--;
	}
	return result;
}

double factRec(int n)
{
	if (n == 0 || n == 1)
	{
		return 1;
	}
	else
	{
		return n * factRec(n - 1);
	}
}

void testFibFact()
{
	for (int i = 0; i < 100; i++)
	{
		printf("Fib of %d is: %g\n", i, fib(i));
		//printf("%d! = %g\n", i, fact(i));
		//printf("Fib of %d is: %g\n", i, fibRec(i));
		//printf("%d = %g\n", i, factRec(i));
	}
}