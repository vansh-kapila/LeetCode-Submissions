class Solution {
public:
    set<vector<int>> s;
    void solve(vector<int> &nums,int i,vector<int> &x)
    {
        if(i==nums.size())
        {   
            vector<int> y = x;
            sort(x.begin(),x.end()); 
            s.insert(x);  
            for(int i=0;i<x.size();i++)
            {
                x[i]=y[i];
            }
            return;
        }
        x.push_back(nums[i]);
        solve(nums,i+1,x);
        x.pop_back();
        solve(nums,i+1,x);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> x;
        solve(nums,0,x);
        vector<vector<int>> ans;
        for(auto i:s)
        {
            ans.push_back(i);
        }
        return ans;
    }
};