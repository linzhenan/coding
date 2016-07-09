#include <stdio.h>
#include <stdlib.h>

void QuickSort(int* nums, int* order, int left, int right)
{
    int i;

    printf("[%d - %d] ", left, right);
    for (i = 0; i < 4; i++)
        printf("%d ", nums[i]);
    printf("\n");

    if (left < right)
    {
        int key = nums[left];
        int id = order[left];
        int low = left;
        int high = right;
        
        while (low < high)
        {
            while (low < high && key <= nums[high])
                high--;
            nums[low] = nums[high];
            order[low] = order[high];
            while (low < high && key >= nums[low])
                low++;
            nums[high] = nums[low];
            order[high] = order[low];
        }
        nums[low] = key;
        order[low] = id;
        QuickSort(nums, order, left, low - 1);
        QuickSort(nums, order, low + 1, right);
    }
}

void main(void)
{
    int nums[] = { 0, 4, 3, 0,};
    int order[] = { 1, 2, 3, 4, };

    QuickSort(nums, order, 0, 4 - 1);
}