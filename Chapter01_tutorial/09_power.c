/*
 * @FilePath: /tcpl-demo/Chapter01_tutorial/09_power.c
 * @Description:  test power function.
 * @Author: kasier houle_he@163.com
 * @Date: 2024-07-08 10:51:41
 * @Version: 0.0.1
 */
#include <stdio.h>

int power(int base, int exponent);

int main(void)
{
	int i;
	for (i = 0; i < 10; i++)
		printf("%d %d %d\n", i, power(2, i), power(3, i));

	return 0;
}

int power(int base, int exponent)
{
	int result = 1;
	while (exponent > 0) {
		result *= base;
		exponent--;
	}

	return result;
}