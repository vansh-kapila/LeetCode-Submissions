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
    map<int,int> inorderind;
    int j=5;
    TreeNode* tree(int l,int r,vector<int> &postorder,vector<int> &inorder)
    {
        if(l>r or j<0)
        {
            return nullptr;
        } 
        int x = postorder[j];  
        j--;
        TreeNode* root = new TreeNode(x); 
        root->right = tree(inorderind[x]+1,r,postorder,inorder);
        root->left = tree(l,inorderind[x]-1,postorder,inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++)
        {
            inorderind[inorder[i]]=i;
        }
        j = postorder.size()-1;
        return tree(0,inorder.size()-1,postorder,inorder);
    }
};