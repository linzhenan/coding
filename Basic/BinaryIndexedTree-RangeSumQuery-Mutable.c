//Using Binary Indexed Tree to solve the leetcode problem Range Sum Query - Mutable
//https://leetcode.com/problems/range-sum-query-mutable/
//Using Segment Tree can also solve the same problem
//http://www.geeksforgeeks.org/segment-tree-set-1-sum-of-given-range/

struct NumArray {
	int *bit;
	int *num;
	int n;
};

int lowbit(int i) {
	int k = i + 1;//BIT is one-based
	return k & -k;
}

void update(struct NumArray* numArray, int i, int val) {
	int diff = val - numArray->num[i];
	numArray->num[i] = val;
	int k;
	do {
		numArray->bit[i] += diff;
		k = lowbit(i);
		i += k;
	} while (i < numArray->n);
}

/** Initialize your data structure here. */
struct NumArray* NumArrayCreate(int* nums, int numsSize) {
	struct NumArray* numArray = malloc(sizeof(struct NumArray));
	numArray->bit = malloc(sizeof(int) * numsSize);
	memset(numArray->bit, 0, sizeof(int) * numsSize);
	numArray->num = malloc(sizeof(int) * numsSize);
	memset(numArray->num, 0, sizeof(int) * numsSize);
	numArray->n = numsSize;

	for (int i = 0; i < numsSize; i++)
		update(numArray, i, nums[i]);

	return numArray;
}

int getSum(struct NumArray* numArray, int i) {
	int sum = 0;

	int k;
	do {
		sum += numArray->bit[i];
		k = lowbit(i);
		i -= k;
	}
	while (i >= 0);

	return sum;
}
int sumRange(struct NumArray* numArray, int i, int j) {
	if (i == 0)
		return getSum(numArray, j);
	else
		return getSum(numArray, j) - getSum(numArray, i - 1);
}

/** Deallocates memory previously allocated for the data structure. */
void NumArrayFree(struct NumArray* numArray) {
	free(numArray->bit);
	free(numArray);
}

// Your NumArray object will be instantiated and called as such:
// struct NumArray* numArray = NumArrayCreate(nums, numsSize);
// sumRange(numArray, 0, 1);
// update(numArray, 1, 10);
// sumRange(numArray, 1, 2);
// NumArrayFree(numArray);

void main() {
	/*
#define COUNT 10
	int nums[COUNT] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int numsSize = COUNT;
	struct NumArray* numArray = NumArrayCreate(nums, numsSize);
	printf("sumRange[0,1] = %d\n", sumRange(numArray, 0, 1));
	update(numArray, 1, 10);
	printf("sumRange[1,2] = %d\n", sumRange(numArray, 1, 2));
	NumArrayFree(numArray);
	*/
#define COUNT 3
	int nums[COUNT] = { 1, 3, 5};
	int numsSize = COUNT;
	struct NumArray* numArray = NumArrayCreate(nums, numsSize);
	printf("sumRange[0,2] = %d\n", sumRange(numArray, 0, 2));
	update(numArray, 1, 2);
	printf("sumRange[0,2] = %d\n", sumRange(numArray, 0, 2));
	NumArrayFree(numArray);
}