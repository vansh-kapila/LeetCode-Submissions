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
    int j = 0;
    TreeNode* tree(int l,int r,vector<int> &preorder,vector<int> &inorder)
    {
        if(l>r)
        {
            return nullptr;
        }
        int x = preorder[j];
        j++;
        TreeNode* root = new TreeNode(x); 
        root->left = tree(l,inorderind[x]-1,preorder,inorder);
        root->right = tree(inorderind[x]+1,r,preorder,inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++)
        {
            inorderind[inorder[i]]=i;
        }
        int j = 0;
        return tree(0,preorder.size()-1,preorder,inorder);
    }
};