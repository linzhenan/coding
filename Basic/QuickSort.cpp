#include <iostream>
using namespace std;
void QuickSort(int *arr, int left, int right) {
	if (left < right) {
		int pivot = arr[left];
		int lo = left;
		int hi = right;
		while (lo < hi) {
			while (lo < hi && arr[hi] >= pivot)
				hi--;
			arr[lo] = arr[hi];
			while (lo < hi && arr[lo] < pivot)
				lo++;
			arr[hi] = arr[lo];
		}
		arr[lo] = pivot;
		QuickSort(arr, left, lo - 1);
		QuickSort(arr, lo + 1, right);
	}
}

int main() {
	int arr0[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int arr1[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int arr2[10] = { 1, 3, 3, 7, 4, 2, 9, 8, 4, 2 };
	QuickSort(arr0, 0, 9);
	QuickSort(arr1, 0, 9);
	QuickSort(arr2, 0, 9);
	for (int i = 0; i < 10; i++)
		cout << arr0[i] << " ";
	cout << endl;
	for (int i = 0; i < 10; i++)
		cout << arr1[i] << " ";
	cout << endl;
	for (int i = 0; i < 10; i++)
		cout << arr2[i] << " ";
	cout << endl;
	return 0;
}
