#include "Algorithms.h"

int BinarySearch(int *array, int key, int left, int right)
{
	int midd;
	while (1)
	{
		midd = (left + right) / 2;
		if (key < array[midd]) right = midd - 1;
		else if (key > array[midd]) left = midd + 1;
		else return midd;
		if (left > right) return -1;
	}
}

void QuickSort(int *array, int left, int right)
{
	int i = left, j = right, temp, pivot = array[(i + j) / 2];

	while (i <= j)
	{
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;
		if (i <= j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
		}
	}
	if (j > left)
		QuickSort(array, left, j);
	if (i < right)
		QuickSort(array, i, right);
}

void InsertionSort(int* array, int size)
{
	int i, j, key;
	for (i = 1; i < size; i++)
	{
		key = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
	}
}

void BogoSort(int* array, int size)
{
	int temp, random;
	while (!checkIfSorted(array, size))
		for (int i = 0; i < size; i++)
		{
			random = rand() % size;
			temp = array[i];
			array[i] = array[random];
			array[random] = temp;
		}
}

void CountingSort(char* array, int size)
{
	int max = 0, i, j = 0;
	int* count;


	for (i = 0; i < size; i++)
	{
		if (max < int(array[i]))
			max = int(array[i]);
	}
	count = new int[max + 1];
	for (i = 0; i <= max; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
	{
		count[int(array[i])]++;
	}
	for (i = 0; i <= max; i++)
	{
		while (count[i] != 0)
		{
			array[j] = i;
			count[i]--;
			j++;
		}
	}

}

bool checkIfSorted(int* array, int size)
{
	for (int i = 0; i <  size - 1; i++)
		if (array[i] > array[i + 1]) return false;
	return true;
}

bool checkIfSorted(char* array, int size)
{
	for (int i = 0; i < size - 1; i++)
		if (array[i] > array[i + 1]) return false;
	return true;
}