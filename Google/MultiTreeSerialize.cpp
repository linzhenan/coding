#include <vector>
#include <queue>
#include <sstream>

using namespace std;

class TreeNode {
public:
	int val;
	int n;
	TreeNode **next;
	TreeNode (int v) : val(v) { n = 0; next = NULL; }
};

class Solution {
public:
	string tree2str(TreeNode *root) {
		queue<TreeNode *> q;
		q.push(root);
		string str = "";
		while (!q.empty()) {
			TreeNode *node = q.front();
			q.pop();
			if (node) {
				stringstream ss;
				ss << node->val;
				ss << ",";
				ss << node->n;
				ss << ";";
				str += ss.str();
				for (int idx = 0; idx < node->n; idx++)
					q.push(node->next[idx]);
			}
		}
		return str;
	}
	TreeNode* str2tree(string str) {
		TreeNode *root = NULL;
		queue<TreeNode **> q;
		q.push(&root);
		for (int i = 0; i < str.size(); i++) {
			string substr = "";
			while (str[i] != ',')
				substr += str[i++];
			i++;

			TreeNode *node = new TreeNode(atoi(substr.c_str()));

			substr.clear();
			while (str[i] != ';')
				substr += str[i++];

			int cnum = atoi(substr.c_str());
			node->n = cnum;
			if (cnum) {
				node->next = (TreeNode **)malloc(sizeof(TreeNode*) * cnum);
				for (int idx = 0; idx < cnum; idx++)
					q.push(&node->next[idx]);
			}

			TreeNode **pp = q.front();
			q.pop();
			(*pp) = node;
		}
		return root;
	}
};

void main() {
	
	TreeNode *node1 = new TreeNode(1);
	TreeNode *node2 = new TreeNode(2);
	TreeNode *node3 = new TreeNode(3);
	TreeNode *node4 = new TreeNode(4);
	TreeNode *node5 = new TreeNode(5);
	TreeNode *node6 = new TreeNode(6);
	TreeNode *node7 = new TreeNode(7);

	node1->n = 3;
	node1->next = (TreeNode **)malloc(sizeof(TreeNode*) * 3);
	node1->next[0] = node2;
	node1->next[1] = node3;
	node1->next[2] = node4;

	node2->n = 1;
	node2->next = (TreeNode **)malloc(sizeof(TreeNode*) * 1);
	node2->next[0] = node5;

	node4->n = 2;
	node4->next = (TreeNode **)malloc(sizeof(TreeNode*) * 2);
	node4->next[0] = node6;
	node4->next[1] = node7;

	Solution slu;
	string str = slu.tree2str(node1);
	TreeNode *node = slu.str2tree(str);
}