#include <stdlib.h>

typedef struct Node {
	int val;
	struct Node *next;
}
Node;
typedef struct Stack {
	Node *top;
	Node *bottom;
	int size;
}
Stack;
void init(Stack *stk) {
	stk->top = malloc(sizeof(Node));
	stk->top->next = NULL;
	stk->bottom = stk->top;
	stk->size = 0;
}
void destroy(Stack *stk) {
	while (stk->top) {
		stk->bottom = stk->top->next;
		free(stk->top);
		stk->top = stk->bottom;
	}
	stk->size = 0;
}
void push(Stack *stk, int val) {
	if (stk->top == stk->bottom) {
		stk->top->next = malloc(sizeof(Node));
		stk->bottom = stk->top->next;
		stk->bottom->val = val;
		stk->bottom->next = NULL;
	}
	else {
		Node *node = malloc(sizeof(Node));
		node->val = val;
		node->next = stk->top->next;
		stk->top->next = node;
	}
	stk->size++;
}
void pop(Stack *stk) {
	if (stk->top->next == stk->bottom) {
		free(stk->top->next);
		stk->top->next = NULL;
		stk->bottom = stk->top;
	}
	else {
		Node *node = stk->top->next;
		stk->top->next = node->next;
		free(node);
	}
	stk->size--;
}
int top(Stack *stk) {
	return stk->top->next->val;
}
int size(Stack *stk) {
	return stk->size;
}
int empty(Stack *stk) {
	if (stk->size == 0)
		return 1;
	else
		return 0;
}
int maximalRectangle(char** matrix, int matrixRowSize, int matrixColSize) {
	int h = matrixRowSize;
	int w = matrixColSize;
	if (h == 0 || w == 0)
		return 0;
	int *height = malloc(sizeof(int)*(w + 1));
	memset(height, 0, sizeof(int)*(w + 1));
	int maxval = 0;
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			if (x < w) {
				if (matrix[y][x] == '0')
					height[x] = 0;
				else
					height[x]++;
			}
		}
		Stack stk;
		init(&stk);
		for (int x = 0; x <= w;) {
			if (empty(&stk) || height[x] > height[top(&stk)]) {
				push(&stk, x++);
			}
			else {
				int pos = top(&stk);
				pop(&stk);
				maxval = max(maxval, height[pos] * (empty(&stk) ? x : x - top(&stk) - 1));
			}
		}
		destroy(&stk);
	}
	free(height);
	return maxval;
}

void main() {
	char **matrix = (char **)malloc(sizeof(char*) * 6);
	matrix[0] = "000100";
	matrix[1] = "001100";
	matrix[2] = "001100";
	matrix[3] = "001101";
	matrix[4] = "101111";
	matrix[5] = "111111";
	printf("%d\n", maximalRectangle(matrix, 6, 6));
}