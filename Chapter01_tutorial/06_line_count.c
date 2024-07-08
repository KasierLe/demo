/*
 * @FilePath: /tcpl-demo/Chapter01_tutorial/06_line_count.c
 * @Description:  
 * @Author: kasier houle_he@163.com
 * @Date: 2024-07-08 10:12:01
 * @Version: 0.0.1
 */
#include <stdio.h>

int main(void)
{
	int lines_count = 0;
	int ch;

	while ((ch = getchar()) != EOF) {
		if (ch == '\n')
			++lines_count;
	}

	printf("Number of lines: %d\n", lines_count);

	return 0;
}