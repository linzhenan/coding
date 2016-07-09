//http://www.geeksforgeeks.org/segment-tree-set-1-sum-of-given-range/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int constructStDFS(int arr[], int left, int right, int idx, int *st) {
	if (left == right) {
		st[idx] = arr[left];
		return st[idx];
	}

	int mid = left + (right - left) / 2;
	st[idx] = constructStDFS(arr, left, mid, idx * 2 + 1, st) +
			  constructStDFS(arr, mid + 1, right, idx * 2 + 2, st);
	return st[idx];
}
int *constructST(int arr[], int n) {
	int N = 1 << (int)(ceil(log2(n)));
	int *st = malloc(sizeof(int) * (2 * N - 1));
	//memset(st, 0, sizeof(int) * N);
	constructStDFS(arr, 0, n - 1, 0, st);
	return st;
}
int *destroyST(int *st) {
	free(st);
	return NULL;
}
void updateValueDFS(int arr[], int left, int right, int idx, int *st, int pos, int diff) {
	if (left == right) {
		arr[pos] += diff;
		st[idx] += diff;
		return;
	}
	st[idx] += diff;
	int mid = left + (right - left) / 2;
	if (pos <= mid)
		updateValueDFS(arr, left, mid, idx * 2 + 1, st, pos, diff);
	else
		updateValueDFS(arr, mid + 1, right, idx * 2 + 2, st, pos, diff);
}
void updateValue(int arr[], int n, int pos, int val, int *st) {
	int diff = val - arr[pos];
	if (pos < 0 || pos >= n)
		return;
	updateValueDFS(arr, 0, n - 1, 0, st, pos, diff);
}
int getSumDFS(int *st, int left, int right, int qleft, int qright, int idx) {
	if (right < qleft || qright < left) {
		return 0;
	}
	else if (qleft <= left && right <= qright) {
		return st[idx];
	}
	else {
		int mid = left + (right - left) / 2;
		return getSumDFS(st, left, mid, qleft, qright, idx * 2 + 1) +
			   getSumDFS(st, mid + 1, right, qleft, qright, idx * 2 + 2);
	}
}
int getSum(int *st, int n, int qleft, int qright) {
	if (0 <= qleft && qleft <= qright && qright < n)
		return getSumDFS(st, 0, n - 1, qleft, qright, 0);
	else
		return -1;
}
void main() {
#define COUNT 7
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, };
	int *st = constructST(arr, COUNT);

	printf("Sum[1,3] = %d\n", getSum(st, COUNT, 1, 3));
	updateValue(arr, COUNT, 1, 10, st);
	printf("Sum[1,3] = %d\n", getSum(st, COUNT, 1, 3));

	st = destroyST(st);
}