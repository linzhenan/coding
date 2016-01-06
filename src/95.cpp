//Unique Binary Search Trees II

class Solution {
private:
	vector<TreeNode *> generate(int start, int end) {
		vector<TreeNode *> subTree;
		if (start > end) {
			return subTree;
		}
		for (int k = start; k <= end; k++) {
			vector<TreeNode *> leftSubs = generate(start, k - 1);
			vector<TreeNode *> rightSubs = generate(k + 1, end);
			if (leftSubs.size() == 0 && rightSubs.size() == 0) {
				TreeNode *node = new TreeNode(k);
				node->left = NULL;
				node->right = NULL;
				subTree.push_back(node);
			}
			else if (leftSubs.size() == 0 && rightSubs.size() != 0) {
				for (auto j : rightSubs) {
					TreeNode *node = new TreeNode(k);
					node->left = NULL;
					node->right = j;
					subTree.push_back(node);
				}
			}
			else if (leftSubs.size() != 0 && rightSubs.size() == 0) {
				for (auto i : leftSubs) {
					TreeNode *node = new TreeNode(k);
					node->left = i;
					node->right = NULL;
					subTree.push_back(node);
				}
			}
			else {
				for (auto i : leftSubs) {
					for (auto j : rightSubs) {
						TreeNode *node = new TreeNode(k);
						node->left = i;
						node->right = j;
						subTree.push_back(node);
					}
				}
			}
		}
	}
public:
	vector<TreeNode *> generateTrees(int n) {
		return generate(1, n);
	}
};