class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int index = -1;
        int sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum>=target)
            {
                index = i;
                break;
            }
        }
        if(index==-1)
        {
            return 0;
        }
        int j = 0;
        int ans = nums.size();
        for(int i=index+1;i<nums.size();i++)
        {
            while(sum-nums[j]>=target)
            {
                sum=sum-nums[j];
                j++;
            }
            ans = min(i-j,ans);
            sum = sum+nums[i];
        }
        while(sum-nums[j]>=target)
            {
                sum=sum-nums[j];
                j++;
            }
        int x = nums.size();
        ans=min(ans,x-j);
        return ans;
    }
};