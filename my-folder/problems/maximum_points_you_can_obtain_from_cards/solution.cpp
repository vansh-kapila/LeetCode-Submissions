class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        
        int ans = 0;
        int sum = 0;
        for(int i=0;i<k;i++)
        {
            ans = ans+nums[i];
        }
        sum = max(sum,ans);
        int j = nums.size()-1;
        for(int i=k-1;i>=0;i--)
        {    
            ans=ans-nums[i]+nums[j];
            j--;
            sum = max(sum,ans);
        }
        return sum;
    }
};