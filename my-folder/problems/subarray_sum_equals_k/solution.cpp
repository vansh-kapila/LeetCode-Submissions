class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> m;
        int pre = 0;
        m[pre]++;
        int ans = 0;
        for(auto i:nums)
        {
            pre+=i;
            ans=ans+m[pre-k];
            m[pre]++;
        }
        return ans;
    }
};