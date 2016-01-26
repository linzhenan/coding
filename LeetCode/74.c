//Search a 2D Matrix

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
	int m = matrixRowSize;
	int n = matrixColSize;
	int low = 0;
	int high = m - 1;
	while (low < high) {
		if (matrix[low][0] == target || matrix[high][n - 1] == target)
			return true;
		if (matrix[low][0] > target || matrix[high][n - 1] < target)
			return false;
		int mid = (low + high) >> 1;
		if (matrix[mid][n - 1] >= target)
			high = mid;
		else if (matrix[mid + 1][0] <= target)
			low = mid + 1;
		else
			return false;
	}
	int left = 0;
	int right = n - 1;
	while (left <= right) {
		if (matrix[low][left] == target || matrix[low][right] == target)
			return true;
		int mid = (left + right) >> 1;
		if (matrix[low][mid] == target)
			return true;
		else if (matrix[low][mid] > target)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return false;
}