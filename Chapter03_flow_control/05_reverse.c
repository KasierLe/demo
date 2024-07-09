/*
 * @FilePath: /tcpl-demo/Chapter03_flow_control/05_reverse.c
 * @Description:  
 * @Author: kasier houle_he@163.com
 * @Date: 2024-07-09 09:46:57
 * @Version: 0.0.1
 */
#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void local_itoa(int n, char s[]);
int local_trim(char s[]);

int main()
{
	char arr[] = "hello, world";
	for (int i = 0; i < sizeof(arr) / sizeof(char); i++)
		printf("%c", arr[i]);
	printf("\n");

	reverse(arr);
	for (int i = 0; i < sizeof(arr) / sizeof(char); i++)
		printf("%c", arr[i]);
	printf("\n");

	char ptr[100];
	local_itoa(123456789, ptr);
	printf("%s\n", ptr);

	strcat(arr, "  \t\n\t\t");
	int len = local_trim(arr);
	printf("%d\n", len);
	printf("%s\n", arr);

	return 0;
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
	int i, j;
	char temp;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}

/* itoa: convert intenger to character*/
void local_itoa(int n, char s[])
{
	int i = 0, sign = n;

	if (sign < 0)
		n = -n;

	do {
		s[i++] = n % 10 + '0';
	} while (n /= 10);

	if (sign < 0)
		s[i++] = '-';

	s[i] = '\0';

	reverse(s);
}

/* trim: remove trailing blanks, tabs, newlines */
int local_trim(char s[])
{
	int n;
	for (n = strlen(s) - 1; n >= 0; n--) {
		if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
			break;
	}
	s[n + 1] = '\0';

	return n + 1;
}