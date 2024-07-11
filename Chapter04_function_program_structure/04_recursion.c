/*
 * @FilePath: /tcpl-demo/Chapter04_function_program_structure/04_recursion.c
 * @Description:  
 * @Author: kasier houle_he@163.com
 * @Date: 2024-07-10 14:36:32
 * @Version: 0.0.1
 */
#include <stdio.h>

void printd(int n);

int main(void)
{
	printd(-1234);

	return 0;
}

/* printd: print n in decimal */
void printd(int n)
{
	if (n < 0) {
		putchar('-');
		n = -n;
	}

	if (n / 10)
		printd(n / 10);

	putchar(n % 10 + '0');
}