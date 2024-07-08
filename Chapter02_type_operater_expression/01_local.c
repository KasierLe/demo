/*
 * @FilePath: /tcpl-demo/Chapter02_type_operater_expression/01_local.c
 * @Description:  
 * @Author: kasier houle_he@163.com
 * @Date: 2024-07-08 16:35:30
 * @Version: 0.0.1
 */
#include <stdio.h>

int local_atoi(char *str);
int local_strlen(char *str);
int local_lower(int ch);

int main(void)
{
	char str[100] = "12345";
	char ptr[100] = "hello, world";

	printf("atoi: %d\n", local_atoi(str));
	printf("strlen: %d\n", local_strlen(ptr));
	printf("lower: %c\n", local_lower('A'));

	return 0;
}

/* atoi: convert string to integer */
int local_atoi(char *str)
{
	int n = 0;

	for (int i = 0; str[i] >= '0' && str[i] <= '9'; i++)
		n = n * 10 + str[i] - '0';

	return n;
}

/* strlen: return length of s */
int local_strlen(char *str)
{
	int n = 0;

	for (int i = 0; str[i] != '\0'; i++)
		n++;

	return n;
}

/* lower: convert c to lower case; ASCII only */
int local_lower(int ch)
{
	if (ch >= 'A' && ch <= 'Z')
		return ch + 'a' - 'A';
	else
		return ch;
}