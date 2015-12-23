//Rotate Image
void swap(int *a, int *b) {
	if (a != b) {
		*a ^= *b;
		*b ^= *a;
		*a ^= *b;
	}
}
void rotate(int** matrix, int matrixRowSize, int matrixColSize) {
	for (int i = 0; i < matrixRowSize; i++) {
		for (int j = 0; j < i; j++) {
			swap(&matrix[i][j], &matrix[j][i]);
		}
	}
	for (int i = 0; i < matrixRowSize; i++) {
		for (int j = 0; j < matrixColSize / 2; j++) {
			swap(&matrix[i][j], &matrix[i][matrixColSize - 1 - j]);
		}
	}
}