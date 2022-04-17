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
    vector<int> v;
    void inorder(TreeNode* root){
        if(root==nullptr)
        {
            return;
        }
        inorder(root->left); 
        v.push_back(root->val);
        inorder(root->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
         
         inorder(root);
         TreeNode* dummy = new TreeNode(0); 
         TreeNode* ans = dummy;
         for(auto i:v)
         {   
             //cout<<i<<endl; 
             ans->right = new TreeNode(i);
             ans = ans->right;
         }
         return dummy->right;
    }
};