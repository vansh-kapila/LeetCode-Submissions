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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr)
        {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        ans.push_back({root->val});
        while(!q.empty())
        { 
            vector<TreeNode*> v;
            while(!q.empty())
            {
                auto x = q.front();
                q.pop();
                if(x->left!=nullptr)
                {
                    v.push_back(x->left);
                }
                if(x->right!=nullptr)
                {
                    v.push_back(x->right);
                }
            }
            if(v.empty())
            {
                break;
            }
            vector<int> val;
            for(auto i:v)
            {
                q.push(i);
                val.push_back(i->val);
            }
            ans.push_back(val);
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};