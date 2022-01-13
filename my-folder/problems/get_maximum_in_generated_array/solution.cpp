class Solution {
public:
    int getMaximumGenerated(int n) {
        int dp[n+1];
        if(n==0)
        {
            return 0;
        }
        for(int i=0;i<n+1;i++)dp[i]=0;
        dp[0]=0;
        dp[1]=1;
        
        for(int i=1;i<=n/2;i++)
        {
            dp[2*i]=dp[i];
            if(2*i+1<=n){
            dp[2*i+1]=dp[i]+dp[i+1];}
        } 
        int ans = 0;
        for(int i=0;i<n+1;i++)
        {
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};