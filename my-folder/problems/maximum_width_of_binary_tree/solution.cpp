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
        int widthOfBinaryTree(TreeNode *root)
        {
            queue<pair<TreeNode*, int>> q;
            q.push({ root,1 });
            int ans = 1;
            while (!q.empty())
            {
                vector<pair<TreeNode*, int>> v;
                unsigned int offset = q.front().second;
                while (!q.empty())
                {
                    if (q.front().first->left != nullptr)
                    {
                        v.push_back({ q.front().first->left,2*(q.front().second-offset)});
                    }
                    if (q.front().first->right != nullptr)
                    {
                        v.push_back({ q.front().first->right,2*(q.front().second-offset)+1 });
                    }
                    q.pop();
                }
                if (!v.empty())
                {
                    ans = max(ans, v[v.size() - 1].second - v[0].second + 1);
                }
                for (auto i: v)
                {
                    q.push(i);
                }
            }
            return ans;
        }
};