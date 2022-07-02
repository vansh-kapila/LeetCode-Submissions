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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root==nullptr)
        {
            return ans;
        }
        q.push(root);
        ans.push_back({root->val});
        int count = 0;
        while(!q.empty())
        {
            vector<TreeNode*> v;
            count++;
            while(!q.empty())
            {
                if(q.front()->left!=nullptr)
                {
                    v.push_back(q.front()->left);
                }
                if(q.front()->right!=nullptr)
                {
                    v.push_back(q.front()->right);
                }
                q.pop();
            }
            vector<int> store;
            for(auto i:v)
            {
                q.push(i);
                store.push_back(i->val);
            }
            if(count%2)
            {
                reverse(store.begin(),store.end());
            }
            if(store.empty())
            {
                break;
            }
            ans.push_back(store);
        }
        return ans;
    }
};