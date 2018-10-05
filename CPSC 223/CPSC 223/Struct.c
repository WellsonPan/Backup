//Structures
#include <stdio.h>
#include <stdbool.h>
#include "Struct.h"
#include "Pointers.h"

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define MAXWORD 100

struct point
{
	int x;
	int y;
};

typedef struct point point;

struct rect
{
	point ul;
	point lr;
};

typedef struct rect rect;

struct circle
{
	point center;
	int radius;
};

typedef struct circle circle;

struct elipse
{
	point center;
	double semimajor;
	double semiminor;
};

typedef struct elipse elipse;

struct node
{
	char* content;
	int number;
};

typedef struct node node;

struct bstNode
{
	char* content;
	struct bstNode* left;
	struct bstNode* right;
};

typedef struct bstNode bstNode;

struct bstIntNode
{
	int value;
	struct bstIntNode* left;
	struct bstIntNode* right;
};

typedef struct bstIntNode bstIntNode;


void printPoint(point pt)
{
	printf("{%d, %d}\n", pt.x, pt.y);
}

void printRect(char *msg, rect r)
{
	printf("\n%s ul(%d, %d), lr(%d, %d)\n", msg, r.ul.x, r.ul.y, r.lr.x, r.lr.y);
}

void printCircle(char *msg, circle c)
{
	printf("\n%s center(%d, %d), radius = %d\n", msg, c.center.x, c.center.y, c.radius);
}

void printElipse(char *msg, elipse e)
{
	printf("\n%s is: ctr:(%d, %d), semimajor = %.2f, semiminor = %.2f", msg, e.center.x, e.center.y, e.semimajor, e.semiminor);
}

void printNode(node n)
{
	printf("%s, freq:%d\n", n.content, n.number);
}

point makePoint(int x, int y)
{
	point pt = { x, y };
	//pt.x = x;
	//pt.y = y;
	return pt;
}

rect makeRect(point ul, point lr)
{
	rect r = { ul, lr };
	return r;
}

circle makeCircle(point center, int radius)
{
	circle c = { center, radius };
	return c;
}

elipse makeElipse(point center, double semimajor, double semiminor)
{
	elipse e = { center, semimajor, semiminor };
	return e;
}

bool pointInRect(point pt, rect r)
{
	//ul is 10, 20  lr is 500, 800  pt is 50, 10
	//this still needs work
	if (pt.x >= r.ul.x && pt.x < r.lr.x && pt.y >= r.ul.y && pt.y < r.lr.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

struct rect canonRect(rect r) //non-pointers
{
	struct rect temp;

	temp.ul.x = min(r.ul.x, r.lr.x);
	temp.ul.y = min(r.ul.y, r.lr.y);
	temp.lr.x = max(r.ul.x, r.lr.x);
	temp.lr.y = max(r.ul.y, r.lr.y);

	return temp;
}

struct rect canon_rect(rect *pr) //pointers
{
	rect temp;
	//temp.ul.x = min((*pr).ul.x, (*pr).lr.x); don't do this
	temp.ul.x = min(pr->ul.x, pr->lr.x);
	temp.ul.y = min(pr->ul.y, pr->lr.y);
	temp.lr.x = max(pr->ul.x, pr->lr.x);
	temp.lr.y = max(pr->ul.y, pr->lr.y);

	return temp;

}

static void incDecNode(node* n, int count)
{
	n->number += count;
}

void incNode(node *n)
{
	//n->number++;
	incDecNode(n, 1);
	//printf("in incNode, n is now %s, freq; %d\n", n.content, n.number);
}

void decNode(node *n)
{
	//n->number--;
	incDecNode(n, -1);
}

node keytab[] = { { "auto", 0 },{ "break", 0 },{ "case", 0 },{ "char", 0 },{ "const", 0 },{ "continue", 0 },{ "default", 0 },{ "unsigned", 0 },{ "void", 0 },{ "volatile", 0 },{ "while", 0 } };

#define NKEYS (sizeof(keytab) / sizeof(node))

int binsearch(char* word, node tab[], int n)
{
	int cond;
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if ((cond = (word, tab[mid].content)) < 0)
		{
			high = mid - 1;
		}
		else if (cond > 0)
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

int getword(char *word, int lim)
{
	int c;
	char *w = word;

	while (isspace(c = getch_()))
	{
		;
	}
	if (c != EOF)
	{
		*w++ = c;
	}
	if (!isalpha(c))
	{
		*w = '\0';
		return c;
	}
	for (; --lim > 0; w++)
	{
		if (!isalnum(*w = getch_()))
		{
			ungetch_(*w);
			break;
		}
	}
	*w = '\0';
	return word[0];
}

int countCKeywords()
{
	int n;
	char word[MAXWORD];

	while (getword(word, MAXWORD) != EOF)
	{
		if (isalpha(word[0]))
		{
			if ((n = binsearch(word, keytab, NKEYS)) >= 0)
			{
				incNode(&keytab[n]);
			}
		}
	}
	for (n = 0; n < NKEYS; ++n)
	{
		if (keytab[n].number > 0)
		{
			printNode(keytab[n]);
		}
	}
	return 0;
}

struct tnode
{
	char* word;
	int count;
	struct tnode* left;
	struct tnode* right;
};

typedef struct tnode tnode;


tnode* talloc_()
{
	return (tnode*)malloc(sizeof(tnode));
}

char* strdup_(char *s)
{
	char *p;

	p = (char*)malloc(strlen(s) + 1); // +1 for '\0'
	if (p != NULL)
	{
		strcopy_(p, s);
	}
	return p;
}

tnode* addtree(tnode* p, char* w)
{
	int cond;

	if (p == NULL)
	{
		p = talloc_();
		p->word = strdup_(w);
		p->count = 1;
		p->left = p->right = NULL;
	}
	else if ((cond = strcmp(w, p->word)) == 0)
	{
		p->count++;
	}
	else if (cond < 0)
	{
		p->left = addtree(p->left, w);
	}
	else
	{
		p->right = addtree(p->right, w);
	}
	return p;
}

void printTree(tnode *p)
{
	if (p == NULL)
	{
		return;
	}
	else
	{
		printTree(p->left);
		printf("%d, %s\n", p->count, p->word);
		printTree(p->right);
	}
}

bool searchTree(tnode *p, char* w)
{
	int cond;
	if (p == NULL)
	{
		printf("end of tree ...  word not found\n");
		return false;
	}
	if ((cond = strcmp(w, p->word)) == 0)
	{
		printf("word found!\n");
		return true;
	}
	else if (cond < 0)
	{
		printf("looking left\n");
		return searchTree(p->left, w);
	}
	else
	{
		printf("looking right\n");
		return searchTree(p->right, w);
	}
}

tnode* buildTree()
{
	tnode* root;
	char word[MAXWORD];

	root = NULL;
	while (getword(word, MAXWORD) != EOF)
	{
		if (isalpha(word[0]))
		{
			root = addtree(root, word);
		}
	}
	printTree(root);
	return root;
}
