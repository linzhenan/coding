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
    unordered_map<int, UndirectedGraphNode*> map;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node)
            return NULL;
        if (map.find(node->label) != map.end())
            return map[node->label];//avoid loop
        UndirectedGraphNode* new_node = new UndirectedGraphNode(node->label);
        map[node->label] = new_node;
        for (auto e : node->neighbors)
            new_node->neighbors.push_back(cloneGraph(e));
        return new_node;
    }
};