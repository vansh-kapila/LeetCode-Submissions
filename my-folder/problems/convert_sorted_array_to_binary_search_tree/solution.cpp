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
    TreeNode* tree(int l,int r,vector<int> &nums)
    {
        if(l>r)
        {
            return nullptr;
        }
        int mid = (l+r)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = tree(l,mid-1,nums);
        root->right = tree(mid+1,r,nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        return tree(0,nums.size()-1,nums);
    }
};