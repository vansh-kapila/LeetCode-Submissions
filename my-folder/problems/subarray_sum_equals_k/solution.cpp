class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        int sum = 0;
        int ans = 0;
        mp[0]++;
        for(auto i:nums)
        {
            sum=sum+i;
            ans+=mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};