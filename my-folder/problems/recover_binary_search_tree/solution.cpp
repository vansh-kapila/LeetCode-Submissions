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
    vector<TreeNode *> v;
    void inorder(TreeNode* root)
    {
        if(!root)
        {
            return;
        }
        inorder(root->left);
        v.push_back(root);
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        int pivot = -1;
        for(int i=0;i<v.size()-1;i++)
        {
            if(v[i]->val>v[i+1]->val)
            {
                pivot = i;
                break;
            }
        }
        int pivot2 = v.size()-1;
        for(int i=pivot+1;i<v.size();i++)
        {
            if(v[pivot]->val>v[i]->val)
            {
                pivot2 = i; 
            } 
        }
       // cout<<v[pivot]->val<<' '<<v[pivot2]->val<<endl;
        TreeNode* x = v[pivot];
        TreeNode* y = v[pivot2];
        swap(x->val,y->val);
    }
};