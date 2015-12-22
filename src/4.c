double findMedianSortedArraysOn(int *nums1, int nums1Size, int *nums2, int nums2Size) {
    int len = nums1Size + nums2Size;
    int *nums = malloc(sizeof(int) * len);
    int i = 0, j = 0, k = 0;
    
    while (k < len) {
        if (i == nums1Size && j != nums2Size) {
            nums[k++] = nums2[j++];
            continue;
        }
        if (i != nums1Size && j == nums2Size) {
            nums[k++] = nums1[i++];
            continue;
        }
        if (nums1[i] < nums2[j]) {
            nums[k++] = nums1[i++];
            continue;
        }
        else {
            nums[k++] = nums2[j++];
            continue;
        }
    }
    
    if (len % 2 == 0)
        return 0.5 * (nums[len / 2 - 1] + nums[len / 2]);
    else
        return nums[len / 2];
        
    free(nums);
}

int min(int a, int b) {
    if (a < b)
        return a;
    else
        return b;
}
double findKthNum(int* a, int m, int* b, int n, int k) {
    if (m > n)
        return findKthNum(b, n, a, m, k);
    if (m == 0)
        return b[k - 1];
    if (k == 1)
        return min(a[0], b[0]);
    
    int pa = min(k / 2, m);
    int pb = k - pa;
    if(a[pa - 1] < b[pb -1])
        return findKthNum(a + pa, m - pa, b, n, k - pa);
    else if(a[pa - 1] > b[pb - 1])
        return findKthNum(a, m, b + pb, n - pb, k - pb);
    else
        return a[pa - 1];
}

double findMedianSortedArraysOlog(int *nums1, int nums1Size, int* nums2, int nums2Size) {
    int len = nums1Size + nums2Size;
    if (len % 2 == 0)
        return (findKthNum(nums1, nums1Size, nums2, nums2Size, len / 2) + 
                findKthNum(nums1, nums1Size, nums2, nums2Size, len / 2 + 1)) * 0.5;
    else
        return findKthNum(nums1, nums1Size, nums2, nums2Size, len / 2 + 1);
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    //return findMedianSortedArraysOn(nums1, nums1Size, nums2, nums2Size);
    return findMedianSortedArraysOlog(nums1, nums1Size, nums2, nums2Size);
}