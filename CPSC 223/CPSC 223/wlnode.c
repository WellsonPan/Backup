#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "Pointers.h"
#include "wlnode.h"
#include "LongestLine.h"

#define MAXWORD 100
#define MAXLINE 1000

char *noisewords[] = {"a", "the", "to", "and", "of", "or"};
#define NOISESIZE sizeof(noisewords)/sizeof(char*)

struct wlnode
{
	char * word;
	int count;
	int linenumbers;
	int prev_lineno;
	int* list_lineno;
	struct wlnode *left;
	struct wlnode * right;
};

typedef struct wlnode wlnode;

wlnode* wlalloc()
{
	return (wlnode*)malloc(sizeof(wlnode));
}

char* strdup_wl(char *s)
{
	char *p;

	p = (char*)malloc(strlen(s) + 1); // +1 for '\0'
	if (p != NULL)
	{
		strcopy_(p, s);
	}
	return p;
}

char* rtrim(char* p)
{
	int i, len = (int)strlen(p);

	for (i = 0; i < len && p[i] == '\n'; ++i)
	{
	}
	char *dupe = strdup_wl(p);
	dupe[i + len] = '\0';
	return dupe;
}

wlnode* addtree_wl(wlnode* p, char *w, int lineno)
{
	int cond;
	//char buf[50];
	if (p == NULL)
	{
		p = wlalloc();
		p->word = strdup_wl(rtrim(w));
		p->count = 1;
		p->linenumbers = 1;
		p->prev_lineno = lineno;
		p->list_lineno = (int*)malloc(sizeof(int) * 100);
		p->list_lineno[0] = lineno;
		p->left = p->right = NULL;
	}
	else if ((cond = strcmp(w, p->word)) == 0)
	{
		p->count++;
		if (p->prev_lineno != lineno) 
		{
			p->list_lineno[p->linenumbers] = lineno;
			p->linenumbers++;
		}
	}
	else if (cond < 0)
	{
		p->left = addtree_wl(p->left, w, lineno);
	}
	else
	{
		p->right = addtree_wl(p->right, w, lineno);
	}
	return p;
}

int comp_wlnode(wlnode* lhs, wlnode* rhs) {
	return lhs->linenumbers - rhs->linenumbers;
}

void inorder_traversal_wl(wlnode* p, wlnode* array[], int* pi) {
	if (p == NULL) { return;  }
	inorder_traversal_wl(p->left, array, pi);
	array[(*pi)++] = p;
	inorder_traversal_wl(p->right, array, pi);
}

void printtreenode_wl(wlnode* p) {
	if (strlen(p->word) > 0) {
		printf("%d %s: ", p->count, p->word);
		for (int i = 0; i < p->linenumbers; ++i) {
			printf("%d ", p->list_lineno[i]);
		}
		printf("\n");
	}
}

void printtree_wl(wlnode* p) {
	if (p == NULL) { return; }
	printtree_wl(p->left);
	printtreenode_wl(p);
	printtree_wl(p->right);
}

bool checknoise(char *p)
{
	char buf[50];
	strcopy_(buf, p);
	for (int i = 0; i < NOISESIZE; ++i)
	{
		if (stricmp(buf, noisewords[i]) == 0)
		{
			return true;
		}
	}
	return false;
}

wlnode* build_tree_wl() {
	wlnode* root;
	char buf[MAXLINE];
	const char* terminators = " ,.-!?\t\n";
	int len = 0;
	int lineno = 0;

	root = NULL;
	while ((len = getline_(buf, MAXLINE)) != 0 && buf[0] != '\n') {
		char* p = strtok(buf, terminators);
		while (p != NULL) {
			if (!checknoise(p)) { root = addtree_wl(root, p, lineno);}
			p = strtok(NULL, terminators);
		}
		++lineno;
	}
	printf("\n===TREE BUILT\n");
	printtree_wl(root);
	return root;
}

void shellsort_wl(wlnode* v[], int n)
{
	int gap, i, j;
	wlnode *temp;

	for (gap = n / 2; gap > 0; gap /= 2)
	{
		for (i = gap; i < n; i++)
		{
			for (j = i - gap; j >= 0 && comp_wlnode(v[j], v[j + gap]) < 0; j -= gap)
			{
				temp = v[j];
				v[j] = v[j + gap];
				v[j + gap] = temp;
			}
		}
	}
}

void test_wl()
{
	wlnode* p = build_tree_wl();
	//printf("The root word is: %s", p->word);
	wlnode* list[MAXWORD];
	//int counter = 0;
	int size = (sizeof(list) / sizeof(wlnode*));
	int i = 0;
	printf("=========================================================\n");
	inorder_traversal_wl(p, list, &i);
	for (int j = 0; list[i] != 0 && j < i; ++j) {
		printtreenode_wl(list[j]);
	}
	printf("=========================================================\n");
	shellsort_wl(list, i);
	for (int j = 0; list[j] != 0 && j < i; ++j) {
		printtreenode_wl(list[j]);
	}
}