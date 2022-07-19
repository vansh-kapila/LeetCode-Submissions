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
    bool SameTree(TreeNode* p,TreeNode* q)
    {
        if(q==nullptr and p==nullptr)
        {
            return 1;
        }
        if(p==nullptr or q==nullptr)
        {
            return 0;
        }
        if(p->val!=q->val)
        {
            return 0;
        }
        return SameTree(p->right,q->right)&SameTree(p->left,q->left);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) { 
        if(root==nullptr)
        {
            return 0;
        } 
        if(SameTree(root,subRoot))
        {
            return 1;
        }
        return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
    }
};