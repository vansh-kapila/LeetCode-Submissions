class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int> &nums,vector<int> &v,int target,int i)
    {
        if(target<0)
        {
            return;
        }
        if(target==0)
        { 
            ans.push_back(v);
            return;
        }
        if(i==nums.size())
        {
            return;
        }
        for(int j=i;j<nums.size();j++)
        {
            if(j>i and nums[j]==nums[j-1])continue;
            if(nums[j]>target)return; 
            v.push_back(nums[j]);
            solve(nums,v,target-nums[j],j+1); 
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> v;
        sort(candidates.begin(),candidates.end());
        solve(candidates,v,target,0); 
        return ans;
    }
};