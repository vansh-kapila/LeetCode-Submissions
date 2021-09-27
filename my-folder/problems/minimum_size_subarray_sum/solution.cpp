class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        
    
        int pre[n+1];
        pre[0]=0;
        pre[1] = nums[0];
        
        for(int i=2;i<n+1;i++)
        {
            pre[i]=pre[i-1]+nums[i-1];
        }
        
        int ans = 1000000007;
        int k = 0;
        if(pre[n]<target)
        {
            return 0;
        }
        for(int i=1;i<n+1;i++)
        {   
            while(pre[i]-pre[k]>=target)
            {   ans = min(ans,i-k);
                k++;
            }
        }
        
        return ans;
    }
};