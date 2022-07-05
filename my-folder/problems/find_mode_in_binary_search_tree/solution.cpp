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
    void inorder(TreeNode* root)
    {
        if(root==nullptr)
        {
            return;
        }
        
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        unordered_map<int,int> mp;
        int maxx = 0;
        for(auto i:v)
        {
            mp[i]++;
            maxx = max(maxx,mp[i]);
        }
        vector<int> ans;
        for(auto i:mp)
        {
            if(i.second==maxx)
            {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};