/*
 * @FilePath: /tcpl-demo/Chapter01_tutorial/10_getline.c
 * @Description:  
 * @Author: kasier houle_he@163.com
 * @Date: 2024-07-08 11:12:08
 * @Version: 0.0.1
 */
#include <stdio.h>

#define MAXLINE 1000

int local_getline(char line[], int maxline);
void copy(char to[], char from[]);

int main(void)
{
	int line_len, max_line_len = 0;
	char line[MAXLINE];
	char longest_line[MAXLINE];

	while ((line_len = local_getline(line, MAXLINE)) > 0) {
		if (line_len > max_line_len) {
			max_line_len = line_len;
			copy(longest_line, line);
		}
	}

	if (max_line_len > 0)
		printf("The longest line is: %s\n", longest_line);

	return 0;
}

int local_getline(char line[], int maxline)
{
	int ch, line_len = 0;

	while ((ch = getchar()) != EOF && ch != '\n' &&
	       line_len < maxline - 1) {
		line[line_len++] = ch;
	}
	if (ch == '\n') {
		line[line_len++] = ch;
	}
	line[line_len] = '\0';

	return line_len;
}

void copy(char to[], char from[])
{
	int i;

	for (i = 0; from[i] != '\0'; i++) {
		to[i] = from[i];
	}
	to[i] = '\0';
}