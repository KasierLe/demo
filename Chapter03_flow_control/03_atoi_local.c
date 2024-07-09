/*
 * @FilePath: /demo/Chapter03_flow_control/03_atoi_local.c
 * @Description:  如果有空白符的话，则跳过; 如果有符号的话，则读取符号; 取整数部分，并执行转换
 * @Author: kasier houle_he@163.com
 * @Date: 2024-07-08 21:20:31
 * @Version: 0.0.2
 */
#include <stdio.h>
#include <ctype.h>

int local_atoi(char *str);

int main(void)
{
	char str[100] = "    -12345hello";

	printf("original string: %s\n", str);
	printf("converted integer: %d\n", local_atoi(str));

	return 0;
}

/* atoi: convert s to integer; version 2 */
int local_atoi(char *str)
{
	int i, sign, n;

	for (i = 0; isspace(str[i]); i++)
		;

	sign = ((str[i] == '-') ? -1 : 1);
	if (str[i] == '+' || str[i] == '-')
		i++;

	for (n = 0; isdigit(str[i]); i++)
		n = 10 * n + (str[i] - '0');

	return sign * n;
}
