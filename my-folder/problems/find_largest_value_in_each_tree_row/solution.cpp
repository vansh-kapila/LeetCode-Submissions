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
    vector<int> largestValues(TreeNode* root) {
        if(!root)
        {
            vector<int> v;
            return v;
        }
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        ans.push_back(root->val);
        while(!q.empty())
        {
            int n = q.size();
            long long p = -1e10;
            while(n--)
            {
                auto it = q.front();
                q.pop();
                if(it->left!=nullptr)
                {
                    q.push(it->left);
                    int y = it->left->val;
                    p = max(p,(long long)y);
                }
                if(it->right!=nullptr)
                {
                    q.push(it->right);
                    p = max(p,(long long)it->right->val);
                }
            }
            if(p!=-1e10)
            {
                ans.push_back(p);
            }
        }
        return ans;
    }
};