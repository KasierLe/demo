/*
 * @FilePath: /demo/Chapter04_function_program_structure/test_source/getop.c
 * @Description:  
 * @Author: kasier houle_he@163.com
 * @Date: 2024-07-09 20:42:29
 * @Version: 0.0.1
 */
#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* getop: get next character or numeric operand */
int getop(char s[])
{
	char ch;
	int index = 0;

	while ((s[0] = ch = getch()) == ' ' || ch == '\t')
		;
	s[1] = '\0';

	if (!isdigit(ch) && ch != '.')
		return ch;

	if (isdigit(ch)) {
		while (isdigit(s[++index] = ch = getch()))
			;
	}

	if (ch == '.')
		while (isdigit(s[++index] = ch = getch()))
			;

	s[index] = '\0';

	if (ch != EOF)
		ungetch(ch);

	return NUMBER;
}

#define BUFSIZE 100
char buffer[BUFSIZE];
int bufp = 0;

int getch(void)
{
	return (bufp > 0) ? buffer[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buffer[bufp++] = c;
}