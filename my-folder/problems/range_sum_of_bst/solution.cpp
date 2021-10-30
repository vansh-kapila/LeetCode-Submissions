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
    #define range rangeSumBST
    int rangeSumBST(TreeNode* root, int low, int high) {
         if(root==NULL)
         {
            return 0;
         }
         if(root->val<=high and root->val>=low)
        {
            return root->val+range(root->right,low,high)+range(root->left,low,high);
        }
        
         if(root->val>high)
        {
            return range(root->left,low,high); 
        }
        
         
        return range(root->right,low,high); 
        
    }
     
};