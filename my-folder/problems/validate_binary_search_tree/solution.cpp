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
    bool isValidBST(TreeNode* root) {
        return check(root,nullptr,nullptr);
    }
    
    bool check(TreeNode* root,TreeNode* minnode,TreeNode* maxnode)
    {
        if(root==nullptr)
        {
            return 1;
        }
        if((minnode and root->val<=minnode->val) or (maxnode and root->val>=maxnode->val))
        {
            return 0;
        }
        return check(root->left,minnode,root)&check(root->right,root,maxnode);
    }
};