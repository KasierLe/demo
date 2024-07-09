/*
 * @FilePath: /demo/Chapter04_function_program_structure/test_source/calc.h
 * @Description:  
 * @Author: kasier houle_he@163.com
 * @Date: 2024-07-09 20:42:34
 * @Version: 0.0.1
 */
#ifndef CALC_H
#define CALC_H

#define NUMBER '0' /* signal that a number was found */

int getop(char s[]);
int getch(void);
void ungetch(int c);
void push(double f);
double pop(void);

#endif