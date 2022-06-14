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
    vector<TreeNode*> solve(int start, int end)
    {
        if (end < start)
        {
            return {NULL};
        }
        vector<TreeNode*> ans;
        for (int root = start; root <= end; root++)
        {
            vector<TreeNode*> leftTree;
            vector<TreeNode*> rightTree;
            leftTree = solve(start, root - 1);
            rightTree = solve(root + 1, end);
            for(auto l:leftTree)
            {
                for(auto r:rightTree)
                {
                    TreeNode* newRoot = new TreeNode(root);
                    newRoot->left = l;
                    newRoot->right = r;
                    ans.push_back(newRoot);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n)
    {
        set<int> taken;
        return solve(1,n);
    }
};