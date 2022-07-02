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
    unordered_map<TreeNode*,int> store;
    int depth(TreeNode* root)
    {
        if(root==nullptr)
        {
            return 0;
        } 
        if(store.find(root)!=store.end())
        {
            return store[root];
        }
        return store[root]=1+max(depth(root->left),depth(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
          
        if(root==nullptr)
        {
            return 0;
        }
        int ans = 0;
        ans = max({diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right),depth(root->right)+depth(root->left),ans});
        return ans;
    }
};