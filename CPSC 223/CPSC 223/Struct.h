#ifndef Struct_h
#define Struct_h

#include <stdio.h>

struct point;
typedef struct point point;
struct rect;
typedef struct rect rect;
struct circle;
typedef struct circle circle;
struct elipse;
typedef struct elipse elipse;
struct node;
typedef struct node node;
struct bstNode;
typedef struct bstNode bstNode;
struct bstIntNode;
typedef struct bstIntNode bstIntNode;
void printPoint(point pt);
void printRect(char *msg, rect r);
void printCircle(char *msg, circle c);
void printElipse(char *msg, elipse e);
void printNode(node n);
point makePoint(int x, int y);
rect makeRect(point ul, point lr);
circle makeCircle(point center, int radius);
elipse makeElipse(point center, double semimajor, double semiminor);
bool pointInRect(point pt, rect r);
struct rect canonRect(rect r); //non-pointers
struct rect canon_rect(rect *pr); //pointers 
static void incDecNode(node* n, int count);
void incNode(node *n);
void decNode(node *n);

//node keytab[] = { { "auto", 0 },{ "break", 0 },{ "case", 0 },{ "char", 0 },{ "const", 0 },{ "continue", 0 },{ "default", 0 },{ "unsigned", 0 },{ "void", 0 },{ "volatile", 0 },{ "while", 0 } };

#define NKEYS (sizeof(keytab) / sizeof(node))

int binsearch(char* word, node tab[], int n);
int getword(char *word, int lim);
int countCKeywords();
struct tnode;
typedef struct tnode tnode;
tnode* talloc_();
char* strdup_(char *s);
tnode* addtree(tnode* p, char* w);
void printTree(tnode *p);
bool searchTree(tnode *p, char* w);
tnode* buildTree();

#endif /*end of Struct_h*/
