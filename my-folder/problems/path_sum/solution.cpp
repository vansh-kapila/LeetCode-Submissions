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
    bool solve(TreeNode* root,vector<int> &nodes,int sum)
    {    
        if(root==nullptr)
        {
            return 0;
        }
        if(sum==root->val and root->left==nullptr and root->right==nullptr)
        {  
            return 1;
        }
        bool ans = 0;
        nodes.push_back(root->val);
        ans = ans|solve(root->right,nodes,sum-root->val); 
        ans = ans|solve(root->left,nodes,sum-root->val);  
        nodes.pop_back();
        return ans;
        
    } 
    bool hasPathSum(TreeNode* root, int targetSum) {
        vector<int> nodes;
        return solve(root,nodes,targetSum);
    }
};