#include <stdio.h>
#include <stdlib.h>
#include "LongestLine.h"
#pragma warning(disable: 4996)

#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdarg.h>
char *COMPANY = "Stuff N Things";
char *AUTHOR = "Wellson Pan";
char *COPYRIGHT = "2017";
void showversion() {
	printf("diff (LINETEXT) 0.001");
	printf("Copyright (C) %s,%s\n", COMPANY, COPYRIGHT);

	printf("This program comes with NO WARRANTY, to the extent permitted by law.\n");
	printf("You may redistribute copies of this program\n");
	printf("under the terms of the GNU General Public License.\n");
	printf("For more information about these matters, see the file named COPYING.\n");

	printf("Written by %s,\n", AUTHOR);
	printf("\n");
}
void ShowHelp() {
	printf("Usage: diff [OPTION]... FILES\n");
	printf("\tCompare files line by line.\n\n");

	printf("\t-i  --ignore-case  Ignore case differences in file contents.\n");
	printf("\t--ignore-file-name-case  Ignore case when comparing file names.\n");
	//    --no-ignore-file-name-case  Consider case when comparing file names.
	//    -E  --ignore-tab-expansion  Ignore changes due to tab expansion.
	//    -b  --ignore-space-change  Ignore changes in the amount of white space.
	//    -w  --ignore-all-space  Ignore all white space.
	//    -B  --ignore-blank-lines  Ignore changes whose lines are all blank.
	//    -I RE  --ignore-matching-lines=RE  Ignore changes whose lines all match RE.
	//    --strip-trailing-cr  Strip trailing carriage return on input.
	//    -a  --text  Treat all files as text.
	//    
	//    -c  -C NUM  --context[=NUM]  Output NUM (default 3) lines of copied context.
	//    -u  -U NUM  --unified[=NUM]  Output NUM (default 3) lines of unified context.
	//    --label LABEL  Use LABEL instead of file name.
	//    -p  --show-c-function  Show which C function each change is in.
	//    -F RE  --show-function-line=RE  Show the most recent line matching RE.
	//    -q  --brief  Output only whether files differ.
	//    -e  --ed  Output an ed script.
	//    --normal  Output a normal diff.
	//    -n  --rcs  Output an RCS format diff.
	//    -y  --side-by-side  Output in two columns.
	//    -W NUM  --width=NUM  Output at most NUM (default 130) print columns.
	//    --left-column  Output only the left column of common lines.
	//    --suppress-common-lines  Do not output common lines.
	//    -D NAME  --ifdef=NAME  Output merged file to show `#ifdef NAME' diffs.
	//    --GTYPE-group-format=GFMT  Similar, but format GTYPE input groups with GFMT.
	//    --line-format=LFMT  Similar, but format all input lines with LFMT.
	//    --LTYPE-line-format=LFMT  Similar, but format LTYPE input lines with LFMT.
	//    LTYPE is `old', `new', or `unchanged'.  GTYPE is LTYPE or `changed'.
	//    GFMT may contain:
	//    %<  lines from FILE1
	//    %>  lines from FILE2
	//    %=  lines common to FILE1 and FILE2
	//    %[-][WIDTH][.[PREC]]{doxX}LETTER  printf-style spec for LETTER
	//        LETTERs are as follows for new group, lower case for old group:
	//            F  first line number
	//            L  last line number
	//            N  number of lines = L-F+1
	//            E  F-1
	//            M  L+1
	//            LFMT may contain:
	//            %L  contents of line
	//            %l  contents of line, excluding any trailing newline
	//            %[-][WIDTH][.[PREC]]{doxX}n  printf-style spec for input line number
	//                Either GFMT or LFMT may contain:
	//                %%  %
	//                %c'C'  the single character C
	//                %c'\OOO'  the character with octal code OOO
	//                
	//                -l  --paginate  Pass the output through `pr' to paginate it.
	//                -t  --expand-tabs  Expand tabs to spaces in output.
	//                -T  --initial-tab  Make tabs line up by prepending a tab.
	//                
	//                -r  --recursive  Recursively compare any subdirectories found.
	//                -N  --new-file  Treat absent files as empty.
	//                --unidirectional-new-file  Treat absent first files as empty.
	//                -s  --report-identical-files  Report when two files are the same.
	//                -x PAT  --exclude=PAT  Exclude files that match PAT.
	//                -X FILE  --exclude-from=FILE  Exclude files that match any pattern in FILE.
	//                -S FILE  --starting-file=FILE  Start with FILE when comparing directories.
	//                --from-file=FILE1  Compare FILE1 to all operands.  FILE1 can be a directory.
	//                --to-file=FILE2  Compare all operands to FILE2.  FILE2 can be a directory.
	//                
	//                --horizon-lines=NUM  Keep NUM lines of the common prefix and suffix.
	//                -d  --minimal  Try hard to find a smaller set of changes.
	//                --speed-large-files  Assume large files and many scattered small changes.
	//                
	//                -v  --version  Output version info.
	//                --help  Output this help.
	//                
	//                FILES are `FILE1 FILE2' or `DIR1 DIR2' or `DIR FILE...' or `FILE... DIR'.
	//                If --from-file or --to-file is given, there are no restrictions on FILES.
	//                If a FILE is `-', read standard input.
	//                
	//                Report bugs to <bug-gnu-utils@gnu.org>.
}

int diff_(int argc, char *argv[])
{
	if (argc == 1) {
		fprintf(stderr, "diff: Missing operation after diff\n");
		fprintf(stderr, "Diff: Try 'diff --help' for more information.\n");
		exit(2);
	}
	if (strcmp(argv[1], "v") == 0 || strcmp(argv[1], "--version") == 0) {
		showversion();
	}
	if (strcmp(argv[1], "h") == 0 || strcmp(argv[1], "--help") == 0) {
		ShowHelp();
	}

	char fileOne[1000];
	char fileTwo[1000];

	getline_(fileOne, 1000);
	getline_(fileTwo, 1000);

	FILE *f1 = fopen(fileOne, "r");
	FILE *f2 = fopen(fileTwo, "r");

	char c1, c2;

	while ((c1 = fgetc(f1)) != EOF)
	{
		putchar(c1);
	}

	while ((c2 = fgetc(f2)) != EOF)
	{
		putchar(c2);
	}

	return 0;
}