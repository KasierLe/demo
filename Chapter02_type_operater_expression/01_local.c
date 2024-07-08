/*
 * @FilePath: /demo/Chapter02_type_operater_expression/01_local.c
 * @Description:  
 * @Author: kasier houle_he@163.com
 * @Date: 2024-07-08 16:35:30
 * @Version: 0.0.1
 */
#include <stdio.h>

int local_atoi(char *str);
int local_strlen(char *str);
int local_lower(int ch);
void local_squeeze(char *s, int c);
void local_strcat(char *s, char *t);
unsigned int local_getbits(unsigned int x, int p, int n);
int bitcount(unsigned int x);

int main(void)
{
	char str[100] = "12345";
	char ptr[100] = "hello, world";

	printf("atoi: %d\n", local_atoi(str));
	printf("strlen: %d\n", local_strlen(ptr));
	printf("lower: %c\n", local_lower('A'));

	local_strcat(ptr, "!");
	printf("strcat: %s\n", ptr);

	local_squeeze(ptr, 'l');
	printf("squeeze: %s\n", ptr);

	printf("getbits: %d\n", local_getbits(local_atoi(str), 10, 8));
	printf("bitcount: %d\n", bitcount(local_atoi(str)));

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

/* squeeze: delete all c from s */
void local_squeeze(char *s, int c)
{
	int i, j;

	for (i = j = 0; s[i] != '\0'; i++) {
		if (s[i] != c)
			s[j++] = s[i];
	}

	s[j] = '\0';
}

/* strcat: concatenate t to end of s; s must be big enough */
void local_strcat(char *s, char *t)
{
	int i, j;

	i = j = 0;
	while (s[i] != '\0')
		i++;

	while ((s[i++] = t[j++]) != '\0')
		;
}

/* getbits: get n bits from position p */
unsigned int local_getbits(unsigned int x, int p, int n)
{
	return (x >> (p + 1 - n)) & ~(~0 << n);
}

/* bitcount: count 1 bits in x */
int bitcount(unsigned int x)
{
	int count = 0;

	for (; x != 0; x >>= 1) {
		if (x & 01)
			count++;
	}

	return count;
}