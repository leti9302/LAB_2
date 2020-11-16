#include "CppUnitTest.h"
#include "../Lab_2/Algorithms.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		int* a;

		TEST_METHOD_INITIALIZE(setUP)
		{
			srand(time(NULL));
			a = new int[10];
			for (int i = 0; i < 10; i++)
				a[i] = rand();
		}

		TEST_METHOD_CLEANUP(cleanUp) 
		{
			delete [] a;
		}

		TEST_METHOD(bin_test)
		{
			for (int i = 0; i < 10; i++)
				a[i] = i+1;
			Assert::AreEqual(BinarySearch(a, 9, 0, 9), 8);
		}

		TEST_METHOD(bin_test_2)
		{
			for (int i = 0; i < 10; i++)
				a[i] = i + 1;
			Assert::AreEqual(BinarySearch(a, 5, 0, 9), 4);
		}

		TEST_METHOD(bin_test_3)
		{
			for (int i = 0; i < 10; i++)
				a[i] = i + 1;
			Assert::AreEqual(BinarySearch(a, 1, 0, 9), 0);
		}

		TEST_METHOD(bin_test_not_found)
		{
			for (int i = 0; i < 10; i++)
				a[i] = i + 1;
			Assert::AreEqual(BinarySearch(a, 11, 0, 9), -1);
		}

		TEST_METHOD(check_if_sorted_test_for_unsorted)
		{
			Assert::IsFalse(check_if_sorted(a, 10));
		}

		TEST_METHOD(check_if_sorted_test_for_sorted)
		{
			for (int i = 0; i < 10; i++)
				a[i] = i + 1;
			Assert::IsTrue(check_if_sorted(a, 10));
		}

		TEST_METHOD(check_if_sorted_test_for_char_sorted)
		{
			char b[10] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
			Assert::IsTrue(check_if_sorted(b, 10));
		}

		TEST_METHOD(check_if_sorted_test_for_char_unsorted)
		{
			char b[10] = { 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a' };
			Assert::IsFalse(check_if_sorted(b, 10));
		}

		TEST_METHOD(QuickSort_test)
		{
			QuickSort(a, 0, 9);
			Assert::IsTrue(check_if_sorted(a, 10));
		}

		TEST_METHOD(InsertionSort_test)
		{
			InsertionSort(a, 10);
			Assert::IsTrue(check_if_sorted(a, 10));
		}

		TEST_METHOD(BogoSort_test)
		{
			BogoSort(a, 10);
			Assert::IsTrue(check_if_sorted(a, 10));
		}

		TEST_METHOD(CountingSort_test)
		{
			char b[10];
			for (int i = 0; i < 10; i++)
				b[i] = rand() % 128;
			CountingSort(b, 10);
			Assert::IsTrue(check_if_sorted(b, 10));
		}
	};
}
