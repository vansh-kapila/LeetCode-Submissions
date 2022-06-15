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
    int count;
    int ans = -1;
    void inorder(TreeNode* root)
    {
        if(root==nullptr)
        {
            return;
        }
        
        inorder(root->left);
        if(count==1 and ans==-1)
        {
            ans = root->val;  
        }
        else
        {
            count--;
        }
        inorder(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        count = k;
        inorder(root);
        return ans;
    }
};