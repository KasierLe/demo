/*
 * @FilePath: /tcpl-demo/Chapter01_tutorial/02_temperature.c
 * @Description:  Fahrenheit temperatures to Celsius conversion program.
 * @Author: kasier houle_he@163.com
 * @Date: 2024-06-28 15:33:43
 * @Version: 0.0.1
 */
#include <stdio.h>

//print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300

int main(void)
{
	float fahr, celsius;
	float lower = 0; /* lower limit of temperature scale */
	float upper = 300; /* upper limit */
	float step = 20; /* step size */

	fahr = lower;
	while (fahr <= upper) {
		celsius = 5.0 * (fahr - 32) / 9.0;
		printf("%3.0f\t%6.1f\n", fahr, celsius);
		fahr += step;
	}
}