class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int> &candidates,int target,int i,vector<int> x)
    {
        if(target==0)
        {
            ans.push_back(x);
            return;
        }
        for(int j=i;j<candidates.size();j++)
        {
            if(target<candidates[j])
            {
                return;
            }
            x.push_back(candidates[j]);
            helper(candidates,target-candidates[j],j,x);
            x.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> x;
        sort(candidates.begin(),candidates.end());
        helper(candidates,target,0,x);
        return ans;
        
    }
};