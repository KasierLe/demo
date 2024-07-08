/*
 * @FilePath: /tcpl-demo/Chapter01_tutorial/03_temperature_for.c
 * @Description:  
 * @Author: kasier houle_he@163.com
 * @Date: 2024-07-08 09:42:03
 * @Version: 0.0.1
 */
#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

/* print Fahrenheit-Celsius table */
int main(void)
{
	int fahr;

	for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
		printf("%3d %6.2f\n", fahr, (5.0 / 9.0) * (fahr - 32));

	return 0;
}