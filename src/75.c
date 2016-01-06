//Sort Colors

void sortColors(int* nums, int numsSize) {
	int count[3] = { 0 };
	for (int i = 0; i < numsSize; i++)
		count[nums[i]]++;
	int i = 0;
	for (int j = 0; j < 3; j++)
		for (int k = 0; k < count[j]; k++)
			nums[i++] = j;
}