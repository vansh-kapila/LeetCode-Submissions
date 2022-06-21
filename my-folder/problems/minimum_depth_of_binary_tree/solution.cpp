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
    int minDepth(TreeNode* root) {
        
        if(root==nullptr)
        {
            return 0;
        }
        if(root->right==nullptr and root->left==nullptr)
        {
            return 1;
        }
        if(root->right==nullptr or root->left==nullptr)
        {
            return 1+max(minDepth(root->right),minDepth(root->left));
        }
        return 1+min(minDepth(root->right),minDepth(root->left));
    }
};