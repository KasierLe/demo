/*
 * @FilePath: /tcpl-demo/Chapter04_function_program_structure/05_quicksort.c
 * @Description:  
 * @Author: kasier houle_he@163.com
 * @Date: 2024-07-10 14:39:59
 * @Version: 0.0.1
 */
#include <stdio.h>

void quickSort(int v[], int left, int right);
void swap(int v[], int i, int j);
void printArray(int v[], int n);

int main(void)
{
	int arr[] = { 10, 7, 8, 9, 1, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("Original array: \n");
	printArray(arr, n);

	quickSort(arr, 0, n - 1);

	printf("Sorted array: \n");
	printArray(arr, n);

	return 0;
}

void printArray(int v[], int n)
{
	for (int i = 0; i < n; i++) {
		printf("%d ", v[i]);
	}

	printf("\n");
}

/* quickSort: sort v[left...right] */
void quickSort(int v[], int left, int right)
{
	int i, last;

	if (left >= right)
		return;
	swap(v, left, (left + right) / 2); /* move partition elem */
	last = left; /* to v[0] */
	for (i = left + 1; i <= right; i++) /* partition */
	{
		if (v[i] < v[left])
			swap(v, ++last, i);
	}
	swap(v, left, last); /* restore partition elem */
	quickSort(v, left, last - 1);
	quickSort(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(int v[], int i, int j)
{
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}