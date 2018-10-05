#include "LongestLine.h"

#define MAXLINE 1000

int getline_(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
	{
		s[i] = c;
		if (c == '\n')
		{
			s[i] = c;
			i++;
		}
	}
	s[i] = '\0';
	return i;
}

void copy(char *pt, char *pf)
{
	while ((*pt++ = *pf++) != '\0')
	{

	}
}

void reverse(char *s)
{
	int len = 0;
	while (s[len] != '\0')
	{
		len++;
	}

	char temp;
	for (int i = 0; i < (len / 2); i++)
	{
		temp = s[i];
		s[i] = s[len - (i + 1)];
		s[len - (i + 1)] = temp;
	}
}

char* detab(char s[])
{
	int arraySize = (sizeof(s) / sizeof(char));
	int arrayIncrease = 0;
	for (int i = 0; i < arraySize; i++)
	{
		if (s[i] == '\t')
		{
			arrayIncrease++;
		}
	}
	char d[MAXLINE];
	int j = 0;
	int newArraySize = arraySize + (arrayIncrease * 5);
	for (int i = 0; i < newArraySize; i++)
	{
		if (s[i] == '\t')
		{
			int c = 0;
			while (c < 5)
			{
				d[j] = ' ';
				j++;
				c++;
			}
		}
		else
		{
			d[j] = s[i];
		}
	}
	return d;
}