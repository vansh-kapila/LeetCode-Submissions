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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        int count = 1;
        q.push(root);
        vector<double> ans;
        while(!q.empty())
        {
            int x = q.size();
            double sum = 0;
            int yy = x;
            while(x--)
            {
                TreeNode* y = q.front();
                q.pop();
                if(y->left!=nullptr)
                {
                    q.push(y->left);
                }
                if(y->right!=nullptr)
                {
                    q.push(y->right);
                }
                sum = sum+y->val;
            }
            ans.push_back((double)(sum)/(double)yy);
        }
        return ans;
        
    }
};