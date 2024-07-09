/*
 * @FilePath: /tcpl-demo/Chapter04_function_program_structure/02_atof_local.c
 * @Description:  
 * @Author: kasier houle_he@163.com
 * @Date: 2024-07-09 11:30:26
 * @Version: 0.0.1
 */
#include <stdio.h>
#include <ctype.h>

double atof_local(char s[]);

int main(void)
{
	char s[] = "\t\n-123453.6789\n";

	double x = atof_local(s);

	printf("x = %f\n", x);

	return 0;
}

/* atof: convert string s to double */
double atof_local(char s[])
{
	int i, sign;
	double val, power;

	for (i = 0; isspace(s[i]); i++) /* skip white space */
		;

	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;

	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');

	if (s[i] == '.')
		i++;

	for (power = 10.0; isdigit(s[i]); i++, power *= 10.0)
		// val = 10.0 * val + (s[i] - '0');
		val += (s[i] - '0') / power;

	// return sign * val / power;
	return sign * val;
}