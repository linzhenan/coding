//http://www.geeksforgeeks.org/segment-tree-set-1-range-minimum-query/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int minval(int a, int b) {
	if (a < b)
		return a;
	else
		return b;
}
int consturctStDFS(int arr[], int left, int right, int *st, int idx) {
	if (left == right) {
		st[idx] = arr[left];
		return st[idx];
	}
	int mid = left + (right - left) / 2;
	st[idx] = minval(consturctStDFS(arr, left, mid, st, idx * 2 + 1),
					 consturctStDFS(arr, mid + 1, right, st, idx * 2 + 2));
	return st[idx];
}
int* constructSt(int arr[], int n) {
	int N = 1 << (int)(ceil(log2(n)));
	int* st = malloc(sizeof(int) * (2 * N - 1));
	consturctStDFS(arr, 0, n - 1, st, 0);
	return st;
}
int* destroySt(int *st) {
	free(st);
	return NULL;
}
int getMinDFS(int arr[], int left, int right, int qleft, int qright, int *st, int idx) {
	if (right < qleft || qright < left)
		return INT_MAX;
	if (qleft <= left && right <= qright)
		return st[idx];
	int mid = left + (right - left) / 2;
	return minval(getMinDFS(arr, left, mid, qleft, qright, st, idx * 2 + 1),
				  getMinDFS(arr, mid + 1, right, qleft, qright, st, idx * 2 + 2));
}
int getMin(int arr[], int n, int qleft, int qright, int *st, int idx) {
	if (qleft < 0 || qright >= n)
		return INT_MIN;
	return getMinDFS(arr, 0, n - 1, qleft, qright, st, 0);
}
void main() {
#define COUNT 7
	int arr[] = { 1, 2, 3, 7, 5, 6, 4, };
	int *st = constructSt(arr, COUNT);
	printf("Min[0, 6] = %d\n", getMin(arr, COUNT, 0, 6, st, 0));
	printf("Min[2, 4] = %d\n", getMin(arr, COUNT, 2, 4, st, 0));
	printf("Min[4, 6] = %d\n", getMin(arr, COUNT, 4, 6, st, 0));
	st = destroySt(st);
}