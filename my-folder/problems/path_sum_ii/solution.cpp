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
    vector<vector<int>> ans;
    void solve(TreeNode* root,vector<int> &nodes,int sum)
    {    
        if(root==nullptr)
        {
            return;
        }
        if(sum==root->val and root->left==nullptr and root->right==nullptr)
        { 
            nodes.push_back(root->val);
            ans.push_back(nodes);
            nodes.pop_back();
            return;
        }
        nodes.push_back(root->val);
        solve(root->right,nodes,sum-root->val); 
        solve(root->left,nodes,sum-root->val);  
        nodes.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<int> x;
        solve(root,x,targetSum);
        return ans;
    }
};