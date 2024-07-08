/*
 * @FilePath: /tcpl-demo/Chapter01_tutorial/07_word_count.c
 * @Description:  count lines, words, and characters in input.
 * @Author: kasier houle_he@163.com
 * @Date: 2024-07-08 10:17:07
 * @Version: 0.0.1
 */
#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

int main(void)
{
	int ch;
	int lines_count = 0, words_count = 0, chars_count = 0;
	int state = OUT;

	while ((ch = getchar()) != EOF) {
		chars_count++;

		if (ch == '\n')
			lines_count++;

		if (ch == ' ' || ch == '\t' || ch == '\n')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			words_count++;
		}
	}

	printf("Chars: %d\n", chars_count);
	printf("Lines: %d\n", lines_count);
	printf("Words: %d\n", words_count);

	return 0;
}