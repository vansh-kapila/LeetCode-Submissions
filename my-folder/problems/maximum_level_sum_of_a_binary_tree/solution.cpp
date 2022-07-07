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
        int maxLevelSum(TreeNode *root)
        {
            queue<TreeNode*> q;
            q.push(root);
            int count = 1;
            int level = 1;
            int maxsum = root->val;
            while (!q.empty())
            {
                vector<TreeNode*> v;
                int sum = INT_MIN;
                count++;
                while (!q.empty())
                {
                    if (q.front()->left)
                    {
                        if (sum == INT_MIN)
                        {
                            sum = 0;
                        }
                        v.push_back(q.front()->left);
                        sum += v.back()->val;
                    }
                    if (q.front()->right)
                    {
                        if (sum == INT_MIN)
                        {
                            sum = 0;
                        }
                        v.push_back(q.front()->right);
                        sum += v.back()->val;
                    }
                    q.pop();
                }
                if (sum > maxsum)
                {
                    maxsum = sum;
                    level = count;
                }
                for (auto i: v)
                {
                    q.push(i);
                }
            }
            return level;
        }
};