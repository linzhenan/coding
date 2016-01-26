/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void BubbleSort(int* nums, int* order, int numsSize)
{
    int i, j;
    int t;
     
    for (i = 0; i < numsSize - 1; i++)
    {
        for (j = 0; j < numsSize - 1 - i; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                t = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = t;
                t = order[j];
                order[j] = order[j + 1];
                order[j + 1] = t;
            }
        }
    }
}
void QuickSort(int* nums, int* order, int left, int right)
{
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
int* twoSum(int* nums, int numsSize, int target) {
    int i, j;
    int *index, *order;
    int t;
    
    index = malloc(sizeof(int) * 2);
    memset(index, 0, sizeof(int) * 2);
    order = malloc(sizeof(int) * numsSize);
    for (i = 0; i < numsSize; i++)
        order[i] = i + 1;
    
    //BubbleSort(nums, order, numsSize);
    QuickSort(nums, order, 0, numsSize - 1);
    
    i = 0;
    j = numsSize - 1;
    while (i < j)
    {
        if (nums[i] + nums[j] == target)
        {
            if (order[i] < order[j])
            {
                index[0] = order[i];
                index[1] = order[j];
            }
            else
            {
                index[0] = order[j];
                index[1] = order[i];
            }
            break;
        }
        else if (nums[i] + nums[j] < target)
        {
            i++;
        }
        else if (nums[i] + nums[j] > target)
        {
            j--;
        }
    }
    rand()
    free(order);
    return index;
}