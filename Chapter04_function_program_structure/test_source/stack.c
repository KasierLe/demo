/*
 * @FilePath: /demo/Chapter04_function_program_structure/test_source/stack.c
 * @Description:  
 * @Author: kasier houle_he@163.com
 * @Date: 2024-07-09 20:42:45
 * @Version: 0.0.1
 */
#include <stdio.h>
#include "calc.h"

#define MAXVAL 100 /* maximum depth of val stack */
int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}