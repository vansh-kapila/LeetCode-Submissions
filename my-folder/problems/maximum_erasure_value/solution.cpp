class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> mp;
        
        int j=0,ans=0;
        int sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum=sum+nums[i];
            mp[nums[i]]++;
            if(mp[nums[i]]==2)
            {
                while(j<=i and mp[nums[i]]==2)
                {
                    sum=sum-nums[j];
                    mp[nums[j]]--;
                    j++;
                }
            }
            ans = max(ans,sum);
        }
        return ans;
    }
};