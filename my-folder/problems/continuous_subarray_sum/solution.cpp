class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int> pre(nums.size()+1,0);
        for(int i=1;i<=nums.size();i++)
        {
            pre[i]=(pre[i-1]+nums[i-1])%k;
        }
        unordered_map<int,int> mp;
        for(int i=0;i<pre.size();i++)
        {
            if(mp.find(pre[i])!=mp.end() and mp[pre[i]]!=i-1)
            {
                return 1;
            }
            else if(mp.find(pre[i])==mp.end())
            {
                mp[pre[i]]=i;
            }
        }
        return 0;
    }
};