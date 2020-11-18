#include"Algorithms.h"

using namespace std;

void main() {
	int* array1, * array2;
	unsigned dimension = 10;
	double measurings_InsertionSort[10], sum1 = 0;
	double measurings_QuickSort[10], sum2 = 0;
	clock_t begin_time, end_time;
	cout << "Left - InsertionSort, right - QuickSort\n";
	for (int i = 0; i < 5; i++)
	{
		array1 = new int[dimension];
		array2 = new int[dimension];
		for (int i1 = 0; i1 < 10; i1++)
		{
			srand(time(NULL));
			for (int i2 = 0; i2 < dimension; i2++)
			{
				array1[i2] = rand();
				array1[i2] = rand();
			}
			begin_time = clock();
			InsertionSort(array1, dimension);
			end_time = clock() - begin_time;
			measurings_InsertionSort[i1] = ((double)end_time * 1000 / CLOCKS_PER_SEC);
			sum1 += measurings_InsertionSort[i1];
			begin_time = clock();
			QuickSort(array2, 0, dimension - 1);
			end_time = clock() - begin_time;
			measurings_QuickSort[i1] = ((double)end_time * 1000 / CLOCKS_PER_SEC);
			sum2 += measurings_QuickSort[i1];
			cout << measurings_InsertionSort[i1] << ' ' << measurings_QuickSort[i1] << '\n';
		}
		cout << "Average: " << sum1 / 10 << ' ' << sum2 / 10 << '\n';
		sum1 = 0;
		sum2 = 0;
		dimension *= 10;
		delete[] array1;
		delete[] array2;
	}
}