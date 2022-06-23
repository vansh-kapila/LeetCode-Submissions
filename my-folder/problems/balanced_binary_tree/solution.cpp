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
    unordered_map<TreeNode*,int> mdepth;
    int depth(TreeNode* root)
    {
        if(root==nullptr)
        {
            return 0;
        }
        if(mdepth.find(root)!=mdepth.end())
        {
           // return mdepth[root];
        }
        return mdepth[root]=max(depth(root->left),depth(root->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr)
        {
            return 1;
        }
        if(abs(depth(root->right)-depth(root->left))>1)
        {
            return 0;
        }
        return isBalanced(root->left)&isBalanced(root->right);
    }
};