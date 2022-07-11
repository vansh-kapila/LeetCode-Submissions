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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ans;
        if(root==nullptr)
        {
            return ans;
        }
        q.push(root);
        ans.push_back(root->val);
        while(!q.empty())
        {
            vector<TreeNode*> level;
            while(!q.empty())
            {
                auto it = q.front();
                q.pop();
                if(it->right!=nullptr)
                {
                    level.push_back(it->right);
                }
                if(it->left!=nullptr)
                {
                    level.push_back(it->left);
                }
            }
            if(!level.empty())
            {
                ans.push_back(level[0]->val);
            }
            for(auto i:level)
            {
                q.push(i);
            }
        }
        return ans;
    }
};