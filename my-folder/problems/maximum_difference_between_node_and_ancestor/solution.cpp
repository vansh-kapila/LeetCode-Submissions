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
    int ans = 0;
    void solve(TreeNode* root,int maxx,int minn)
    {
         if(root==nullptr)
         {   
             ans = max(ans,maxx-minn);
             return;
         } 
         
         solve(root->left,max(maxx,root->val),min(minn,root->val));
         solve(root->right,max(maxx,root->val),min(minn,root->val));
    }
    
    int maxAncestorDiff(TreeNode* root) {
        solve(root,root->val,root->val);
        return ans;
    }
};