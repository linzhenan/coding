bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    int fieldHash[3][10], hash[10];
    for (int i = 0; i < boardRowSize; i++) {
        memset(hash, 0, sizeof(int) * 10);
        if (i % 3 == 0)
            memset(fieldHash, 0, sizeof(int) * 3 * 10);
        for (int j = 0; j < boardColSize; j++) {
            char ch = board[i][j];
            if (ch == '.')
                continue;
            if (hash[ch - '0'])
                return false;
            else
                hash[ch - '0'] = 1;
            if (fieldHash[j / 3][ch - '0'])
                return false;
            else
                fieldHash[j / 3][ch - '0'] = 1;
        }
    }
    for (int j = 0; j < boardColSize; j++) {
        memset(hash, 0, sizeof(int) * 10);
        for (int i = 0; i < boardRowSize; i++) {
            char ch = board[i][j];
            if (ch == '.')
                continue;
            if (hash[ch - '0'])
                return false;
            else
                hash[ch - '0'] = 1;
        }
    }
    return true;
}