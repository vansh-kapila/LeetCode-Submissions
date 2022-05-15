/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        int solve(TreeNode *root)
        {   
            if(root==nullptr)
            {
                return 0;
            }
            if (root->left == nullptr and root->right == nullptr)
            {
                return root->val;
            }
            if (root->left != nullptr)
            {
                root->left->val = root->val *10 + root->left->val;
            }
            if (root->right != nullptr)
            {
                root->right->val = root->val *10 + root->right->val;
            }
            return solve(root->left) + solve(root->right);
        }
    int sumNumbers(TreeNode *root)
    {
        return solve(root);
    }
};