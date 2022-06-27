/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        int ans = INT_MIN;
    unordered_map<TreeNode*, int> store;
    int solve(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int rightans = 0;
        if (store.find(root->right) != store.end())
        {
            rightans = store[root->right];
        }
        else
        {
            rightans = solve(root->right);
            store[root->right] = rightans;
        }
        int leftans = 0;
        if (store.find(root->left) != store.end())
        {
            leftans = store[root->left];
        }
        else
        {
            leftans = solve(root->left);
            store[root->left] = leftans;
        }
        ans = max({ ans,root->val,rightans + root->val,leftans + root->val,rightans + leftans + root->val });

        return max({ root->val,
            rightans + root->val,
            leftans + root->val });
    }
    int maxPathSum(TreeNode *root)
    {
        solve(root);
        return ans;
    }
};