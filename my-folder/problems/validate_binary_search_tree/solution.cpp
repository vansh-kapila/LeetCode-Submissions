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
        return valid(root,nullptr,nullptr);
    }
    bool valid(TreeNode* root,TreeNode* minnode,TreeNode* maxnode)
    {
        if(root==nullptr)
        {
            return 1;
        }
        if(minnode!=nullptr and root->val<=minnode->val)
        {
            return 0;
        }
        if(maxnode!=nullptr and root->val>=maxnode->val)
        {
            return 0;
        }
        return valid(root->left,minnode,root)&valid(root->right,root,maxnode);
    }
};