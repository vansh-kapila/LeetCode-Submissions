class Solution {
public:
   
    void helper(vector<vector<int>> &ans,vector<int> candidates,int target,int sum,int i,vector<int> x)
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
        helper(ans,candidates,target,sum,i+1,x);
        
        x.push_back(candidates[i]);
        
        helper(ans,candidates,target,sum+candidates[i],i,x);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> x;
        helper(ans,candidates,target,0,0,x);
        return ans;
        
    }
};