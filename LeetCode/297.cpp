#include <string>
#include <queue>
#include <sstream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        string str = "";
        q.push(root);
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if (node) {
                stringstream ss;
                ss << node->val;
                str += ss.str() + ",";
                q.push(node->left);
                q.push(node->right);
            }
            else {
                str += "#,";
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<TreeNode**> q;
        TreeNode* root = NULL;
        q.push(&root);
        for (int i = 0; i < data.size(); i++) {
            if (data[i] == '#') {
                TreeNode **pp = q.front();
                q.pop();
                (*pp) = NULL;
                i++;
            }
            else {
                TreeNode **pp = q.front();
                q.pop();
                string valstr = "";
                while (data[i] != ',')
                    valstr += data[i++];
                TreeNode *node = new TreeNode(atoi(valstr.c_str()));
                (*pp) = node;
                q.push(&node->left);
                q.push(&node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

void main() {
	TreeNode *node1 = new TreeNode(1);
	TreeNode *node2 = new TreeNode(2);
	TreeNode *node3 = new TreeNode(3);
	TreeNode *node4 = new TreeNode(4);
	TreeNode *node5 = new TreeNode(5);
	node1->left = node2;
	node1->right = node3;
	node3->left = node4;
	node4->right = node5;
	Codec codec;
	string str = codec.serialize(node1);
	node1 = codec.deserialize(str);
}