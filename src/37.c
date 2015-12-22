#ifdef WIN32
int isSolved(char board[9][9], int fieldHash[3][3][9], int rowHash[9][9], int colHash[9][9]) {
#else
int isSolved(char **board, int fieldHash[3][3][9], int rowHash[9][9], int colHash[9][9]) {
#endif // WIN32
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] != '.')
				continue;
			for (int k = 0; k < 9; k++) {
				if (!fieldHash[i / 3][j / 3][k] && !rowHash[i][k] && !colHash[j][k]) {
					fieldHash[i / 3][j / 3][k] = 1;
					rowHash[i][k] = 1;
					colHash[j][k] = 1;
					board[i][j] = '1' + k;
					if (isSolved(board, fieldHash, rowHash, colHash))
						return 1;
					fieldHash[i / 3][j / 3][k] = 0;
					rowHash[i][k] = 0;
					colHash[j][k] = 0;
					board[i][j] = '.';
				}
			}
			return 0;
		}
	}
	return 1;
}

#ifdef WIN32
void solveSudoku(char board[9][9], int boardRowSize, int boardColSize) {
#else
void solveSudoku(char **board, int boardRowSize, int boardColSize) {
#endif // WIN32
	int fieldHash[3][3][9] = { 0 };
	int rowHash[9][9] = { 0 };
	int colHash[9][9] = { 0 };
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			char ch = board[i][j];
			if (ch == '.')
				continue;
			int num = ch - '1';
			fieldHash[i / 3][j / 3][num] = 1;
			rowHash[i][num] = 1;
			colHash[j][num] = 1;
		}
	}
	isSolved(board, fieldHash, rowHash, colHash);
}