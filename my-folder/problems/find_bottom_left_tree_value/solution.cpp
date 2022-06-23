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
        int findBottomLeftValue(TreeNode *root)
        {
            queue<TreeNode*> q;
            q.push(root);
            TreeNode * ans;
            ans = root;
            while (!q.empty())
            {
                vector<TreeNode*> store;
                TreeNode *leftn = nullptr;
                while (!q.empty())
                {
                    auto x = q.front();
                    q.pop();
                    if (x->left != nullptr)
                    {
                        store.push_back(x->left);
                        if (leftn == nullptr)
                        {
                            leftn = x->left;
                        }
                    }
                    if (x->right != nullptr)
                    {
                        store.push_back(x->right);
                        if (leftn == nullptr)
                        {
                            leftn = x->right;
                        }
                    }
                }
                if (leftn)
                {
                    ans = leftn;
                }
                for (auto i: store)
                {
                    q.push(i);
                }
            }
            return ans->val;
        }
};