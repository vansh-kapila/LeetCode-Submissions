class Solution {
public:
    bool divisorGame(int n) {
        int dp[n+1];
        if(n==1)
        {
            return false;
        }
        if(n==2)
        {
            return true;
        }
        if(n==3)
        {
            return false;
        }
        dp[1] = 2;
        dp[2] = 1;
        dp[3] = 2;
        for(int i=4;i<=n;i++)
        {
            for(int j=1;j<=(int)sqrt(i)+1;j++)
            {
                if(i%j==0)
                {
                    if(dp[i-j]==2)
                    {   
                        dp[i]=1;
                        break;
                    }
                }
                dp[i]=2;
            }
        }
        
        return 2-dp[n];
    }
};