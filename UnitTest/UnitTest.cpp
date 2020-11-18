#include "CppUnitTest.h"
#include "../Lab_2/Algorithms.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		int* array;

		TEST_METHOD_INITIALIZE(setUP)
		{
			srand(time(NULL));
			array = new int[10];
			for (int i = 0; i < 10; i++)
				array[i] = rand();
		}

		TEST_METHOD_CLEANUP(cleanUp) 
		{
			delete [] array;
		}

		TEST_METHOD(bin_test)
		{
			for (int i = 0; i < 10; i++)
				array[i] = i+1;
			Assert::AreEqual(BinarySearch(array, 9, 0, 9), 8);
		}

		TEST_METHOD(bin_test_2)
		{
			for (int i = 0; i < 10; i++)
				array[i] = i + 1;
			Assert::AreEqual(BinarySearch(array, 5, 0, 9), 4);
		}

		TEST_METHOD(bin_test_3)
		{
			for (int i = 0; i < 10; i++)
				array[i] = i + 1;
			Assert::AreEqual(BinarySearch(array, 1, 0, 9), 0);
		}

		TEST_METHOD(bin_test_not_found)
		{
			for (int i = 0; i < 10; i++)
				array[i] = i + 1;
			Assert::AreEqual(BinarySearch(array, 11, 0, 9), -1);
		}

		TEST_METHOD(checkIfSorted_test_for_unsorted)
		{
			Assert::IsFalse(checkIfSorted(array, 10));
		}

		TEST_METHOD(checkIfSorted_test_for_sorted)
		{
			for (int i = 0; i < 10; i++)
				array[i] = i + 1;
			Assert::IsTrue(checkIfSorted(array, 10));
		}

		TEST_METHOD(checkIfSorted_test_for_char_sorted)
		{
			char array_char[10] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
			Assert::IsTrue(checkIfSorted(array_char, 10));
		}

		TEST_METHOD(checkIfSorted_test_for_char_unsorted)
		{
			char array_char[10] = { 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a' };
			Assert::IsFalse(checkIfSorted(array_char, 10));
		}

		TEST_METHOD(QuickSort_test)
		{
			QuickSort(array, 0, 9);
			Assert::IsTrue(checkIfSorted(array, 10));
		}

		TEST_METHOD(InsertionSort_test)
		{
			InsertionSort(array, 10);
			Assert::IsTrue(checkIfSorted(array, 10));
		}

		TEST_METHOD(BogoSort_test)
		{
			BogoSort(array, 10);
			Assert::IsTrue(checkIfSorted(array, 10));
		}

		TEST_METHOD(CountingSort_test)
		{
			char array_char[10];
			for (int i = 0; i < 10; i++)
				array_char[i] = rand() % 128;
			CountingSort(array_char, 10);
			Assert::IsTrue(checkIfSorted(array_char, 10));
		}
	};
}
