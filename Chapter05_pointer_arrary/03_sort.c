/*
 * @FilePath: /tcpl-demo/Chapter05_pointer_arrary/03_sort.c
 * @Description:  
 * @Author: kasier houle_he@163.com
 * @Date: 2024-07-11 13:58:09
 * @Version: 0.0.1
 */
#include <stdio.h>
#include <string.h>

#define MAXLENS 10

char *lineptr[MAXLENS];

int main(void)
{
	int lines_num = 0;

	while (getline(lineptr[lines_num], MAXLENS) != EOF) {
		lines_num++;
	}

	return 0;
}
