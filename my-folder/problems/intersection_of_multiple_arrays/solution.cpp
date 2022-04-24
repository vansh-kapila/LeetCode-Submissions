class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                m[nums[i][j]]++;
            }
        }
        vector<int> ans;
        for(auto i:m)
        {
            if(i.second==nums.size())
            {
                ans.push_back(i.first);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};