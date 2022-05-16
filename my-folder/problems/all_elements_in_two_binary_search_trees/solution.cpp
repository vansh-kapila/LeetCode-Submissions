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
    vector<int> a;
    vector<int> b;
    void inorder1(TreeNode* root)
    {
        if(root==nullptr)
        {
            return;
        }
        inorder1(root->left);
        a.push_back(root->val);
        inorder1(root->right);
    }  
    void inorder2(TreeNode* root)
    {
        if(root==nullptr)
        {
            return;
        }
        inorder2(root->left);
        b.push_back(root->val);
        inorder2(root->right);
    }  
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        inorder1(root1);
        inorder2(root2);
        vector<int> ans;
        int i = 0;
        int j = 0;
        int n = a.size();
        int m = b.size();
        
        while(i<n and j<m)
        {
            if(a[i]<=b[j])
            {
                ans.push_back(a[i]);
                i++;
            }
            else if(a[i]>b[j])
            {
                ans.push_back(b[j]);
                j++;
            }
        }
        while(i<n)
        {
            ans.push_back(a[i]);
            i++;
        }
        while(j<m)
        {
            ans.push_back(b[j]);
            j++;
        }
        return ans;
    }
};