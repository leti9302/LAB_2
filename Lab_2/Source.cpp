#include"Algorithms.h"

using namespace std;

int main() {
	int j = 0;
	int* a, * b;
	unsigned dimension = 10;
	double measurings_qs[10], sum1 = 0;
	double measurings_is[10], sum2 = 0;
	clock_t begin_time, end_time;
	cout << "Left - InsertionSort, right - QuickSort\n";
	for (int i = 0; i < 5; i++)
	{
		a = new int[dimension];
		b = new int[dimension];
		for (int i1 = 0; i1 < 10; i1++)
		{
			srand(time(NULL));
			for (int i2 = 0; i2 < dimension; i2++)
			{
				a[i2] = rand();
				b[i2] = rand();
			}
			begin_time = clock();
			InsertionSort(b, dimension);
			end_time = clock() - begin_time;
			measurings_is[i1] = ((double)end_time * 1000 / CLOCKS_PER_SEC);
			sum1 += measurings_is[i1];
			begin_time = clock();
			QuickSort(a, 0, dimension - 1);
			end_time = clock() - begin_time;
			measurings_qs[i1] = ((double)end_time * 1000 / CLOCKS_PER_SEC);
			sum2 += measurings_qs[i1];
			cout << measurings_is[i1] << ' ' << measurings_qs[i1] << '\n';
		}
		cout << "Average: " << sum1 / 10 << ' ' << sum2 / 10 << '\n';
		sum1 = 0;
		sum2 = 0;
		dimension *= 10;
		delete[] a;
		delete[] b;
	}
}
