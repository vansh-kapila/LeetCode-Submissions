class Solution
{
    public:
    vector<vector < int>> ans;
    map<int,int> m;
    void solve(vector<int> &v, vector<int> &nums)
    { 
        if (v.size() == nums.size())
        {
            ans.push_back(v); 
            return;
        }
        for (auto j:m)
        {
            if (j.second > 0)
            {
                v.push_back(j.first);
                m[j.first]--;
                solve(v, nums); 
                v.pop_back();
                m[j.first]++;
            }
        } 
    }
    vector<vector < int>> permuteUnique(vector<int> &nums)
    {
        vector<int> v; 
        for (auto i: nums)
        {
            m[i]++;
        }
        solve(v, nums); 
        return ans;
    }
};