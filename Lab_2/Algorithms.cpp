#include "Algorithms.h"

int BinarySearch(int* a, int k, int start, int end)
{
	int m, l = start, r = end;
	while (1)
	{
		m = (l + r) / 2;
		if (k < a[m]) r = m - 1;
		else if (k > a[m]) l = m + 1;
		else return m;
		if (l > r) return -1;
	}
}

void QuickSort(int* a, int l, int r)
{
	int i = l, j = r, temp, piv = a[(i + j) / 2];

	while (i <= j)
	{
		while (a[i] < piv)
			i++;
		while (a[j] > piv)
			j--;
		if (i <= j)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}
	if (j > l)
		QuickSort(a, l, j);
	if (i < r)
		QuickSort(a, i, r);
}

void InsertionSort(int *a, int size)
{
	int i, j, k;
	for (i = 1; i < size; i++)
	{
		k = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > k)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = k;
	}
}

void BogoSort(int* a, int size)
{
	int temp, random;
	while (!check_if_sorted(a, size))
		for (int i = 0; i < size; i++)
		{
			random = rand() % size;
			temp = a[i];
			a[i] = a[random];
			a[random] = temp;
		}
}

void CountingSort(char* a, int size)
{
	int max = 0, i, j = 0;
	int* count;


	for (i = 0; i < size; i++)
	{
		if (max < int(a[i]))
			max = int(a[i]);
	}
	count = new int[max + 1];
	for (i = 0; i <= max; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
	{
		count[int(a[i])]++;
	}
	for (i = 0; i <= max; i++)
	{
		while (count[i] != 0)
		{
			a[j] = i;
			count[i]--;
			j++;
		}
	}

}

bool check_if_sorted(int* a, int size)
{
	for (int i = 0; i <  size - 1; i++)
		if (a[i] > a[i + 1]) return false;
	return true;
}

bool check_if_sorted(char* a, int size)
{
	for (int i = 0; i < size - 1; i++)
		if (a[i] > a[i + 1]) return false;
	return true;
}