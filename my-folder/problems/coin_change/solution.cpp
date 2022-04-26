class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        for(int i=0;i<amount+1;i++)
        {
            dp[i]=1e9+7;
        }
        dp[0]=0;
        int x = *min_element(coins.begin(),coins.end());
        for(int i=0;i<(long long)amount+1+x/(long long)x;i++)
        {   
            for(auto coins:coins)
            {
               if((long long)i+coins<=(long long)amount)
               {
                  dp[i+coins] = min(dp[i+coins],dp[i]+1);
               }
            }
        }
        if(dp[amount]==1e9+7)
        {
            return -1;
        }
        return dp[amount];
    }
};