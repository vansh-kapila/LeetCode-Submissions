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
        if(root==NULL)
        {
            vector<vector<int>> ans;
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> v;
        v.push_back(root->val);
        vector<vector<int>> ans;
        ans.push_back(v);
        v.clear();
        while(!q.empty())
        {
            TreeNode* x = q.front();
            q.pop();
            if(x==NULL and !q.empty())
            {
                q.push(NULL);
                ans.push_back(v);
                v.clear();
            }
            if(x!=NULL and x->left!=NULL)
            {
                q.push(x->left);
                v.push_back(x->left->val);
            }
            if(x!=NULL and x->right!=NULL)
            {
                q.push(x->right);
                v.push_back(x->right->val);
            }
        }
        return ans;
    }
};