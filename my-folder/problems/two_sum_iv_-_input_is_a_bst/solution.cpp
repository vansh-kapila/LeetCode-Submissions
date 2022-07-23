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
    TreeNode* head=nullptr;
    bool find(TreeNode* head,TreeNode* root,int c)
    {
        if(head==nullptr)
        {
            return 0;
        }
        if(head->val==c and head!=root)
        {
            return 1;
        }
        if(head->val>c)
        {
            return find(head->left,root,c);
        }
        else 
        {
            return find(head->right,root,c);
        }
    }
    bool findTarget(TreeNode* root, int k) {
        if(head==nullptr)
        {
            head = root;
        }
        if(root==nullptr)
        {
            return 0;
        }
        if(find(head,root,k-root->val)==1)
        {
            return 1;
        }
        return findTarget(root->right,k)|findTarget(root->left,k);
    }
};