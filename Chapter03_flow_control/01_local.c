/*
 * @FilePath: /demo/Chapter03_flow_control/01_local.c
 * @Description:  
 * @Author: kasier houle_he@163.com
 * @Date: 2024-07-08 19:50:30
 * @Version: 0.0.1
 */
#include <stdio.h>

int local_binsearch(int x, int v[], size_t n1);

int main(void)
{
	int v[] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };

	printf("station = %d\n",
	       local_binsearch(15, v, sizeof(v) / sizeof(int)));

	return 0;
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n1]*/
int local_binsearch(int x, int v[], size_t n1)
{
	int low, high, mid;

	low = 0;
	high = n1 - 1;

	while (low <= high) {
		mid = (low + high) / 2;
		if (v[mid] > x)
			high = mid + 1;
		else if (v[mid] < x)
			low = mid + 1;
		else
			return mid;
	}

	return -1; // no match found
}