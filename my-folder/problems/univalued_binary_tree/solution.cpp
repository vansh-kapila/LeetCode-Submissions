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
    bool isUnivalTree(TreeNode* root) {
        if(root==nullptr)
        {
            return 1;
        }
        if((root->left!=nullptr and root->val!=root->left->val) or (root->right!=nullptr and root->val!=root->right->val))
        {
            return 0;
        }
        
        return isUnivalTree(root->left)&isUnivalTree(root->right);
    }
};