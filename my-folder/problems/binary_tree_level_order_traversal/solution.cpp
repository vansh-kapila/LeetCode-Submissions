/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q; 
        q.push(root);
        vector<vector<int>> ret;
        if(!root)
        {
            return ret;
        }
        ret.push_back({root->val});
        while(!q.empty())
        {
            vector<TreeNode*> v; 
            while(!q.empty())
            {
                v.push_back(q.front()->left);
                v.push_back(q.front()->right);
                q.pop();
            }
            vector<int> store;
            for(auto i:v)
            {
                if(i!=nullptr)
                {
                    q.push(i);
                    store.push_back(i->val);
                }
            }
            if(!store.empty())
            {
              ret.push_back(store);
            }
        }
        return ret;
    }
};