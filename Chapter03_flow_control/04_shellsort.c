/*
 * @FilePath: /tcpl-demo/Chapter03_flow_control/04_shellsort.c
 * @Description:  
 * @Author: kasier houle_he@163.com
 * @Date: 2024-07-08 22:05:33
 * @Version: 0.0.1
 */
#include <stdio.h>

void shellsort(int v[], int n);

int main(void)
{
	int arr[] = { 36, 23, 54, 46, 89, 14, 2, 69, 31, 42, 58 };

	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
		printf("%d ", arr[i]);
	printf("\n");

	shellsort(arr, sizeof(arr) / sizeof(int));
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
		printf("%d ", arr[i]);
}

/* shellsort: sort v[0]...v[n1] into increasing order */
void shellsort(int v[], int n)
{
	int gap, i, j, temp;
	for (gap = n / 2; gap > 0; gap /= 2) {
		for (i = gap; i < n; i++) {
			for (j = i; j >= gap && v[j] < v[j - gap]; j -= gap) {
				temp = v[j];
				v[j] = v[j - gap];
				v[j - gap] = temp;
			}
		}
	}
}