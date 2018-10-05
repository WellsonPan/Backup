#include <stdio.h>
#include "HashTable.h"
#include "Pointers.h"
#include "CalcOperators.h"

#define HASHSIZE 101
#define MAXWORDS 1000

struct nlist
{
	struct nlist *next;
	char *name;
	char *defn;
};
typedef struct nlist nlist;

static nlist *hashtab[HASHSIZE];

unsigned hash(char *s)
{
	unsigned hashval;

	for (hashval = 0; *s != '\0'; s++)
	{
		hashval = *s + 31 * hashval;
	}
	return hashval % HASHSIZE;
}

nlist *lookup(char *s)
{
	nlist *np;

	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
	{
		if (strcmp(s, np->name) == 0)
		{
			return np; //found
		}
	}
	return NULL; //not found
}

char *strdup_ht(char *s)
{
	char *p;

	p = (char *)malloc(strlen(s) + 1);
	if (p != NULL)
	{
		strcopy_(p, s);
	}
	return p;
}

nlist *install(char *name, char *defn)
{
	nlist *np;
	unsigned hashval;

	if ((np = lookup(name)) == NULL)
	{
		np = (nlist *)malloc(sizeof(*np));
		if (np == NULL || (np->name = strdup_ht(name)) == NULL)
		{
			return NULL;
		}
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	}
	else
	{
		free((void*)np->defn);
	}
	if ((np->defn = strdup_ht(defn)) == NULL)
	{
		return NULL;
	}
	return np;
}

void undef_(char *name)
{
	nlist *np;

	if ((np = lookup(name)) != NULL)
	{
		if (np != NULL || (np->name = strdup_ht(name)) != NULL)
		{
			if (np->defn != NULL)
			{
				free((void *)np->defn);
			}
			free((void *) np->name);
		}
	}
}

void testHashTable()
{
	char * names[] = {"I", "You", "He", "Me", "Wumboer", "Wumbology", "It's"};
	char * defns[] = {"Wumbo", "WUMBO", "She", "WuMbO", "Wumboing", "The Study Of Wumbo", "First Grade Spongebob"};
	int size = sizeof(names) / sizeof(char*);

	for (int i = 0; i < size; i++)
	{
		install(names[i], defns[i]);
	}

	for (int i = 0; i < size; i++)
	{
		printf("%s,%s\n", lookup(names[i])->name, lookup(names[i])->defn);
	}

	undef_("Me");
	
	if (lookup("I"))
	{
		printf("I, Wumbo");
	}
}

int getline_ht(char s[], int lim)
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

int preprocess_restofline(FILE * fp)
{
	char c;
	char buf[100], buf1[100], buf2[100];
	int i = 0;
	while ((c = fgetc(fp)) != ' ' && c != '\n')
	{
		buf[i] = c;
		i++;
	}
	buf[i] = '\0';
	i = 0;
	while ((c = fgetc(fp)) != ' ' && c != '\n')
	{
		buf1[i] = c;
		i++;
	}
	buf1[i] = '\0';
	i = 0;
	while ((c = fgetc(fp)) != ' ' && c != '\n' && strcmp(buf, "define") == 0)
	{
		buf2[i] = c;
		i++;
	}
	buf2[i] = '\0';
	if (strcmp(buf, "define") == 0)
	{
		install(buf1, buf2);
	}
	else if(strcmp(buf, "undef") == 0)
	{
		undef_(buf1);
	}
	return 1;
}

int comment(FILE * fp)
{
	char c;
	char buf[100];
	int i = 0;
	while ((c = fgetc(fp)) != '\n' && c != EOF)
	{
		buf[i] = c;
		i++;
	}
	buf[i] = '\0';
	printf("/%s\n", buf);
	return 1;
}

int readword(FILE *fp)
{
	char c;
	char buf[50];
	int i = 0;

	while ((c = fgetc(fp)) != ' ' && c != '\n' && c != ';' && c != ',')
	{
		buf[i] = c;
		i++;
	}
	buf[i] = '\0';

	nlist *np = lookup(buf);
	
	if (np == NULL)
	{
		printf("%s ", buf);
	}
	else
	{
		if (c == ',')
		{
			printf("%s, ", np->defn);
		}
		else
		{
			printf("%s;\n", np->defn);
		}
		return 1;
	}
	return 0;
}

int literal(FILE *fp)
{
	char c;
	char buf[100];
	int i = 0;
	while ((c = fgetc(fp)) != '\"')
	{
		buf[i] = c;
		i++;
	}
	buf[i] = '\0';
	printf("%s\n", buf);
	return 1;
}

int preprocess(char* filename) {
	char c, i = 0;
	int status = 1; // 1 at line begin, 2 for failure, 0 otherwise
	FILE* fp = fopen(filename, "r");
	if (!fp) {
		perror("File opening failed");
		return EXIT_FAILURE;
	}
	printf("===== ===== =====>>> preprocessing beginning <<<===== ===== =====\n");
	while ((c = fgetc(fp)) != EOF) {
		if (isspace(c)) {
			while (isspace(c = fgetc(fp))) {
				putchar(c);
				if (c == '\n') { status = 1; }
			}
		}
		if (c == '#' && status == 1) { status = preprocess_restofline(fp); }
		//else if (c == '\\') { status = backslash(fp); }
		else if (c == '/') { status = comment(fp); }
		//else if (c == '\"') { status = literal(fp); }
		else if (c == EOF) { break; }
		else if (!isalpha(c) && c != '_') { putchar(c); status = 0; }
		else {
			ungetc(c, fp);
			status = readword(fp);
		}
		if (status == 2) { break; }
		++i;
	}
	if (ferror(fp)) { puts("I/O error when reading"); }
	else if (feof(fp)) { puts("End of file reached successfully"); }
	else if (status == 2) { puts("preprocess error"); }
	fclose(fp);
	printf("===== ===== =====>>> preprocessing ending <<<===== ===== =====\n");
	return 0;
}
int test_cpp() {
	int result = preprocess("C:/Users/Wellson/Desktop/testfile.cpp");
	return result;
}