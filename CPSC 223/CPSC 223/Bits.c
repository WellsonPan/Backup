#include <stdio.h>
#include <stdbool.h>
#include "Bits.h"

unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p + 1 - n)) & ~(~0 << n);
}

void test_getbits(unsigned x, int min, int max, int n)
{
	printf("===== testing getbits(unsigned x ,int p, int n) =====\n");
	for (int i = min; i < max; i++)
	{
		printf("getbits(%08x, pos = %d, n = %d) is: %08x\n", x, i, n, getbits(x, i, n));
	}
	printf("===== finished testing getbits =====\n");
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	unsigned i = x;
	i >>= p;
	i <<= p;

	unsigned j = y;
	j <<= ((p - n) + 1);

	unsigned k = x;
	if (p < n)
	{
		k <<= 31;
	}
	else
	{
		k <<= (31 - (p - n));
		k >>= (31 - (p - n));
	}

	return ((i | j) | k);
}

void test_setbits(unsigned x, int p, int max, int step, int n, unsigned y)
{
	printf("===== testing setbits(unsigned x, int p, int n, unsigned y) =====\n");
	for (int index = p; index <= max; index += step)
	{
		printf("getbits(%08x, pos = %d, n = %d) is: %08x\n", x, index, n, setbits(x, index, n, y));
	}
	printf("===== finished testing setbits =====\n");
}

unsigned invert(unsigned x, int p, int n)
{
	unsigned i = x;
	i >>= (p + 1);
	i <<= (p + 1);
	if (p > 27)
	{
		i <<= 8;
		i >>= 8;
	}

	unsigned j = x;
	j >>= (32 - n);
	unsigned l = 0xffffff00;
	j |= l;
	j = ~j;
	j <<= ((p - n) + 1);

	unsigned k = x;
	if (p < n)
	{
		k <<= 31;
	}
	else
	{
		k <<= (31 - (p - n));
		k >>= (31 - (p - n));
	}
	return ((i | j) | k);
}

void test_invert(unsigned x, int p, int max, int step, int n)
{
	printf("===== testing invert(unsigned x, int p, int n) ====\n");
	for (int index = p; index < max; index += step)
	{
		printf("invert(%08x, pos = %d, n = %d) is: %08x\n", x, index, n, invert(x, index, n));
	}
	printf("===== finished testing invert =====\n");
}

unsigned rightrot(unsigned x, int n)
{
	int wordSize = 32;
	return (x << (wordSize - n) | (x >> n));
	//unsigned leftrot = x << wordSize - n;
	//unsigned rightrot = x >> n;

	//unsigned result = leftrot | rightrot;
	//return result;
}

void test_rightrot(unsigned x, int n, int max, int step)
{
	printf("======== Testing rightrot(unsigned x, int n) ========\n");
	for (; n <= max; n += step)
	{
		printf("rightrot(%08x, %02d) is: %08x\n", x, n, rightrot(x, n));
	}
	printf("===== end of test: rightrot(unsigned x, int n) =====\n");
}

unsigned leftrot(unsigned x, int n)
{
	int wordSize = 32;
	return ((x << n) | (x >> (wordSize - n)));
}

void test_leftrot(unsigned x, int n , int max, int step)
{
	printf("======== Testing leftrot(unsigned x, int n) ========\n");
	for (; n <= max; n += step)
	{
		printf("lefttrot(%08x, %02d) is: %08x\n", x, n, leftrot(x, n));
	}
	printf("===== end of test: leftrot(unsigned x, int n) =====\n");
}

unsigned flipBits(unsigned x)
{
	return ~x;
}

/*unsigned flipEveryOtherBit(unsigned x)
{
	unsigned bit = (x &= 1);
	bit = ~bit;
	x &= bit;
}*/

/*bool isEven(unsigned x, int n)
{
	return x & 1;
}

bool isNthBitSet(unsigned x, int n)
{
	return x & (1 << n);
}

bool setNthBit(unsigned x, int n)
{
	return x | (1 << n);
}

bool unsetNthBit(unsigned x, int n)
{
	return x & ~(1 << n);
}

unsigned toggleNthBit(unsigned x, int n)
{
	return x ^ (1 << n);
}

unsigned unsetRightmostBit(unsigned x)
{
	return x & (x - 1);
}

unsigned isolateRightmostBit(unsigned x)
{
	return x & (-x);
}*/