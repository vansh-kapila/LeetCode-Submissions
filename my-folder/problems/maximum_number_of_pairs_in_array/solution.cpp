class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        map<int,int> mp;
        for(auto i:nums)
        {
            mp[i]++;
        }
        int x = 0;
        for(auto i:mp)
        {
            x+=i.second%2;
        }
        int n = nums.size();
        return {(n-x)/2,x};
    }
};