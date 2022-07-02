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
    bool check(vector<TreeNode*> &v,int x)
    { 
        if(!(x%2))
        {
            for(int i=0;i<v.size();i++)
            {
                if(i+1<v.size() and v[i]->val>=v[i+1]->val)
                {
                    return 0;
                }
                if((v[i]->val)%2==0)
                {
                    return 0;
                }
            }
            
        }
        else
        {
            for(int i=0;i<v.size();i++)
            {
                if(i+1<v.size() and v[i]->val<=v[i+1]->val)
                {
                    return 0;
                }
                if((v[i]->val)%2==1)
                {
                    return 0;
                }
            }
            
        }
        return 1;
    }
    bool isEvenOddTree(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        bool ans = 1;
        if(!(root->val%2))
        {
            return 0;
        }
        while(!q.empty())
        { 
            vector<TreeNode*> v;
            int x = q.front().second+1;
            while(!q.empty())
            {
                if(q.front().first->left!=nullptr)
                {
                    v.push_back(q.front().first->left);
                }
                if(q.front().first->right!=nullptr)
                {
                    v.push_back(q.front().first->right);
                }
                q.pop();
            }
            
            if(!check(v,x))
            {
                ans = 0;
                break;
            }
            for(auto i:v)
            {
                q.push({i,x});
            }
        }
        return ans;
    }
};