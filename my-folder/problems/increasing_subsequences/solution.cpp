class Solution {
public:
    set<vector<int>> ans;
    void solve(vector<int> &nums,int i,vector<int> &v)
    {  
        if(v.size()>=2 and is_sorted(v.begin(),v.end()))
        {
            ans.insert(v); 
        }   
        if(i==nums.size())
        {
            return;
        }
        if(v.empty() or nums[i]>=v.back()){
        v.push_back(nums[i]);
        solve(nums,i+1,v);
        v.pop_back();}
        solve(nums,i+1,v);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        vector<int> v;
        solve(nums,0,v);
        vector<vector<int>> anss;
        for(auto i:ans)
        {
            anss.push_back(i);
        }
        return anss;
    }
};