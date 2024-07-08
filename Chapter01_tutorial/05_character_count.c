/*
 * @FilePath: /tcpl-demo/Chapter01_tutorial/05_character_count.c
 * @Description:  
 * @Author: kasier houle_he@163.com
 * @Date: 2024-07-08 10:04:44
 * @Version: 0.0.1
 */
#include <stdio.h>

/* count characters in input; 1st version */
int main(void)
{
	long count = 0;

	while (getchar() != EOF)
		count++;

	printf("Total characters: %ld\n", count);

	return 0;
}
