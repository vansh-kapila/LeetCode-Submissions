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
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root==NULL)
        {   
            delete root;
            return NULL;
        }
        
        else if(key<root->val)
        {
            root->left = deleteNode(root->left,key);
        }
        
        else if(key>root->val)
        {
            root->right = deleteNode(root->right,key);
        }
        else{
        if(root->val==key and root->right==NULL)
        {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        
        else if(root->val==key and root->left==NULL)
        {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        
        else if(root->val==key)
        {
            TreeNode* temp = root->right;
            while(temp->left!=NULL)
            {
                temp=temp->left;
            }
            root->val = temp->val;
            root->right = deleteNode(root->right,temp->val);
        }
    }
        return root;
    }
};