int minimumTotal(int** triangle, int triangleRowSize, int *triangleColSizes) {
    int i, j;
    for (i = triangleRowSize - 2; i >=0; i--)
    {
        for (j = 0; j < triangleColSizes[i]; j++)
        {
            if (*(triangle[i + 1] + j) > *(triangle[i + 1] + (j + 1)))
                triangle[i][j] += *(triangle[i + 1] + (j + 1));
            else
                triangle[i][j] += *(triangle[i + 1] + j);
        }
    }
    return **triangle;
}