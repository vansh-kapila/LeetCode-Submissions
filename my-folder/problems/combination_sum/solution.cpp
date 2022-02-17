class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int> &candidates,int target,int sum,int i,vector<int> x)
    {
        if(sum==target)
        {
            ans.push_back(x);
            return;
        }
        if(sum>target or i>=candidates.size())
        {
            return;
        }
        helper(candidates,target,sum,i+1,x);
        
        x.push_back(candidates[i]);
        
        helper(candidates,target,sum+candidates[i],i,x);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> x;
        helper(candidates,target,0,0,x);
        return ans;
        
    }
};