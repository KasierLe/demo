/*
 * @FilePath: /tcpl-demo/Chapter04_function_program_structure/01_grep_local.c
 * @Description:  
 * @Author: kasier houle_he@163.com
 * @Date: 2024-07-09 10:42:01
 * @Version: 0.0.1
 */
#include <stdio.h>

#define MAXLINE 1000

int local_getline(char *s, int n);
int strindex(char *s, const char *t);

const char pattern[] = "ould"; /* pattern to search for */

int main()
{
	char line[MAXLINE];

	while (local_getline(line, MAXLINE) > 0) {
		if (strindex(line, pattern) >= 0)
			printf("%s", line);
	}

	return 0;
}

/* getline: get line into s, return length */
int local_getline(char *s, int n)
{
	int ch, i = 0;

	while (--n > 0 && (ch = getchar()) != EOF && ch != '\n')
		s[i++] = ch;

	if (ch == '\n')
		s[i++] = ch;

	s[i] = '\0';

	return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char *s, const char *t)
{
	int i, j, k;

	for (i = 0; s[i] != '\0'; i++) {
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			return i;
	}

	return -1;
}
