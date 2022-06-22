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
    
    int solve(TreeNode* root,bool taken,unordered_map<TreeNode*,vector<int>> &dp)
    {
        if(root==nullptr)
        {
            return 0;
        }
        int x = -1;
        if(!dp[root].empty() and dp[root][taken]!=-1)
        {
            return dp[root][taken];
        }
        dp[root] = {-1,-1};
        if(!taken)
        {
            x = root->val + solve(root->right,1,dp)+solve(root->left,1,dp);
        }
        return dp[root][taken] = max(x,solve(root->right,0,dp)+solve(root->left,0,dp));
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,vector<int>> dp;
        return solve(root,0,dp);
    }
};