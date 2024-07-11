/*
 * @FilePath: /tcpl-demo/Chapter05_pointer_arrary/01_getint.c
 * @Description:  
 * @Author: kasier houle_he@163.com
 * @Date: 2024-07-11 09:10:02
 * @Version: 0.0.1
 */
#include <stdio.h>
#include <ctype.h>

#define MAX_ARRAY_SIZE 5

int getint(int *pn);
int getch(void);
void ungetch(int c);

int main(void)
{
	int arr[MAX_ARRAY_SIZE] = { 0 };

	for (int i = 0; i < MAX_ARRAY_SIZE && getint(&arr[i]) != EOF; i++)
		;

	for (int i = 0; i < MAX_ARRAY_SIZE; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}

int getint(int *pn)
{
	int c, sign;

	while (isspace(c = getch())) /* skip white space */
		;

	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		// ungetch(c);
		return c;
	}

	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();

	for (*pn = 0; isdigit(c); c = getch())
		*pn = *pn * 10 + c - '0';

	*pn *= sign;

	if (c != EOF)
		ungetch(c);

	return c;
}

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
