//实现选择排序，包括传入int数组、传入模板、自动生成数组；


#include <iostream>
#include "Student.h"
#include"SortTestHelper.h"

using namespace std;

template<typename T>
void selectionSort(T arr[], int n) {
	for (int i = 0; i < n; i++) {
		//寻找[i,n)区间的最小值
		int minIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
			swap(arr[i], arr[minIndex]);
		}
	}
}

int main()
{
	//选择排序
	int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	selectionSort(a, 10);
	for (int i = 0; i < 10; i++) {
		cout << a[i]<<' ';
	}
	cout << endl;
	/*return 0;*/

	Student d[4] = { {"D", 90}, {"C", 100}, {"B", 95}, {"A", 95} };
	selectionSort(d, 4);
	for (int i = 0; i < 4; i++) {
		cout << d[i];
	}
	cout << endl;
	/*return 0;*/

	int  n = 1000;
	int *arr = SortTestHelper::generateRandomArray(n, 1, 10000);
	//SortTestHelper::printArray(arr, n);
	selectionSort(arr, n);
	//cout << arr[0];
	//SortTestHelper::printArray(arr, n);

	SortTestHelper::testSorted("selectionSort", selectionSort, arr, n);

	delete[] arr;

	return 0;
}

