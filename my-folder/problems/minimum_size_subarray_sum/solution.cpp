class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) { 
        int l = 0;
        int r = 0;
        int sum = 0;
        int ans = 1e9+7;
        int k = target;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            r=i;
            if(sum>=k)
            {   
                while(l<r and sum-nums[l]>=k)
                {      
                    sum=sum-nums[l];
                    l++;
                }
                ans = min(ans,r-l+1);
            }
        }
        if(ans==1000000007)
        {
            return 0;
        }
        return ans; 
    }
};