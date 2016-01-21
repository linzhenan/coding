/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node)
            return NULL;
        UndirectedGraphNode* new_node = new UndirectedGraphNode(node->label);
        for (auto e : node->neighbors)
            new_node->neighbors.push_back(cloneGraph(e));
        return new_node;
    }
};