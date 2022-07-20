/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<Node*,Node*> mp;
    Node* dfs(Node* root)
    {
        if(root==nullptr)
        {
            return nullptr;
        }
        
        if(mp.find(root)==mp.end())
        {
            mp[root] = new Node(root->val,{});
            for(auto i:root->neighbors)
            {
                mp[root]->neighbors.push_back(dfs(i));
            }
        }
        return mp[root];
    }
    Node* cloneGraph(Node* node) {
        return dfs(node); 
    }
};