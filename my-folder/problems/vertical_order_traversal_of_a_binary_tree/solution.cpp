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
    static bool comp(pair<TreeNode*,int> x,pair<TreeNode*,int> y)
    {
        if(x.second==y.second)
        {
            return x.first->val<y.first->val;
        }
        return x.second<y.second;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        map<int,vector<int>> mp;
        mp[0].push_back(root->val);
        while(!q.empty())
        { 
            vector<pair<TreeNode*,int>> v;
            while(!q.empty())
            {
                if(q.front().first->left!=nullptr)
                {
                    v.push_back({q.front().first->left,q.front().second-1});
                }
                if(q.front().first->right!=nullptr)
                {
                    v.push_back({q.front().first->right,q.front().second+1});
                }
                q.pop();
            }
            sort(v.begin(),v.end(),comp);
            for(auto i:v)
            {
                q.push(i);  
                mp[i.second].push_back(i.first->val);
            } 
        }
        vector<vector<int>> ans;
        for(auto &i:mp)
        {
            ans.push_back(i.second);
        } 
        return ans;
    }
};