/*
 * @FilePath: /demo/Chapter03_flow_control/02_count_switch.c
 * @Description:  
 * @Author: kasier houle_he@163.com
 * @Date: 2024-07-08 20:13:03
 * @Version: 0.0.1
 */
#include <stdio.h>

int main(void)
{
	int count_digit[10] = { 0 };
	int ch, block_count = 0, other_count = 0;

	while ((ch = getchar()) != EOF) {
		switch (ch) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			count_digit[ch - '0']++;
			break;
		case ' ':
		case '\t':
		case '\n':
		case '\r':
			block_count++;
			break;
		default:
			other_count++;
			break;
		}
	}

	printf("Digit count: ");
	for (int i = 0; i < 10; i++)
		printf("%d ", count_digit[i]);
	printf(", white space = %d, other = %d\n", block_count, other_count);

	return 0;
}
