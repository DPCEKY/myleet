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
    if(node == NULL)
      return NULL;
    std::queue<std::pair<UndirectedGraphNode *, UndirectedGraphNode *>> q;
    std::unordered_map<int, UndirectedGraphNode *> map;

    UndirectedGraphNode* res = new UndirectedGraphNode(node->label);
    q.push({res, node});

    while(!q.empty()) {
      auto pair = q.front();
      q.pop();

      map.emplace(pair.first->label, pair.first);
      for(int i = 0; i < pair.second->neighbors.size(); i++) {
        if(map.find(pair.second->neighbors[i]->label) != map.end()) {
          pair.first->neighbors.push_back(map[pair.second->neighbors[i]->label]);
          continue;
        }
        UndirectedGraphNode* cp_node = new UndirectedGraphNode(pair.second->neighbors[i]->label);
        pair.first->neighbors.push_back(cp_node);
        q.push({cp_node, pair.second->neighbors[i]});
      }
    }

    return res;
  }
};

