#define LEETCODE29 1
#define LEETCODE37 1
#define LEETCODE38 0

int sign(int x) {
	int tmp1 = x >> 31;
	unsigned int tmp2 = (((unsigned int)(-x))>>31);
	return tmp1|tmp2;
}

void main() {

	int candidates[4] = { 2, 3, 6, 7, };
	int candidatesSize = 4;
	int target = 7;
	int *columnSizes;
	int returnSize;

	int s;
	int s1 = sign(0);
	int s2 = sign(1);
	int s3 = sign(-1);
	int s4 = sign(0x80000000);
	int s5 = sign(0x7FFFFFFF);
	combinationSum(candidates, candidatesSize, target, &columnSizes, &returnSize);
#if LEETCODE38
	countAndSay(2);
#endif

#if LEETCODE37
	char board[9][9] = {
		"..9748...",
		"7........",
		".2.1.9...",
		"..7...24.",
		".64.1.59.",
		".98...3..",
		"...8.3.2.",
		"........6",
		"...2759..",
	};
	solveSudoku(board);
#endif

#if LEETCODE29
	int ans = divide(0x80000000, -2);
	printf("%d\n", ans);
#endif

}