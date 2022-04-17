class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> m;
        for(auto i:nums)
        {
            m[i]++;
        }
        int ans = 0;
        for(auto i:m)
        {
            if(m[i.first]>0 and m[i.first+1]>0)
            {
                ans = max(ans,m[i.first]+m[i.first+1]);
            }
        }
        return ans;
    }
};