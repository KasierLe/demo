/*
 * @FilePath: /demo/Chapter04_function_program_structure/test_source/main.c
 * @Description:  
 * @Author: kasier houle_he@163.com
 * @Date: 2024-07-09 20:41:08
 * @Version: 0.0.1
 */
#include <stdio.h>
#include <stdlib.h> // for atof() function
#include "calc.h"

#define MAXOP 100 /* max size of operand or operator */

int main(void)
{
	int type, op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}

	return 0;
}
