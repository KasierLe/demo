/*
 * @FilePath: /tcpl-demo/Chapter04_function_program_structure/03_external_var.c
 * @Description:  
 * @Author: kasier houle_he@163.com
 * @Date: 2024-07-09 14:09:50
 * @Version: 0.0.1
 */
#include <stdio.h>
#include <stdlib.h> // for atof() function
#include <ctype.h>

#define MAX_OP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

#define MAXVAL 100 /* maximum depth of val stack */
int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

int getop(char[]);
void push(double);
double pop(void);

int getch(void);
void ungetch(int);

int main(void)
{
	int type;
	char arr[MAX_OP];
	double op_temp;

	while ((type = getop(arr) != EOF)) {
		switch (type) {
		case NUMBER:
			push(atof(arr));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '-':
			op_temp = pop();
			push(pop() - op_temp);
			break;
			break;
		case '*':
			push(pop() * pop());
			break;
		case '/':
			op_temp = pop();
			if (op_temp == 0.0)
				printf("error: division by zero\n");
			else
				push(pop() / op_temp);
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", arr);
			break;
		}
	}
	return 0;
}

/* push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL) {
		val[sp++] = f;
	} else {
		printf("error: stack full, can't push %g\n", f);
	}
}

/* pop: pop and return top value from stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

/* getop: get next character or numeric operand */
int getop(char s[])
{
	int i = 0, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';

	if ((!isdigit(c)) && (c != "."))
		return c;

	if (isdigit(c)) /* collect integer part */
	{
		while (isdigit(s[++i] = c = getch()))
			;
	}

	if (c == '.') /* collect fractional part */
	{
		while (isdigit(s[++i] = c = getch()))
			;
	}

	s[i] = '\0';
	if (c != EOF)
		ungetch(c);

	return NUMBER;
}

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

// int getch(void) /* get a (possibly pushedback) character */
// {
// 	return (bufp > 0) ? buf[bufp] : getchar();
// }

int getch(void) /* get a (possibly pushedback) character */
{
	int ch;

	if (bufp > 0)
		return buf[--bufp];

	ch = getchar();
	if (ch != EOF)
		buf[bufp++] = ch;

	return ch;
}

void ungetch(int c) /* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
