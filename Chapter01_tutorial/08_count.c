/*
 * @FilePath: /tcpl-demo/Chapter01_tutorial/08_count.c
 * @Description:  count digits, white space, others.
 * @Author: kasier houle_he@163.com
 * @Date: 2024-07-08 10:43:44
 * @Version: 0.0.1
 */
#include <stdio.h>

int main()
{
	int digit_count[10] = { 0 };
	int ch;
	int space_count = 0, other_count = 0;

	while ((ch = getchar()) != EOF) {
		if (ch >= '0' && ch <= '9')
			digit_count[ch - '0']++;
		else if (ch == ' ' || ch == '\n' || ch == '\t')
			space_count++;
		else
			other_count++;
	}

	printf("Digit count: ");
	for (int i = 0; i < 10; i++)
		printf("%d ", digit_count[i]);
	printf(", white space = %d, other = %d\n", space_count, other_count);

	return 0;
}