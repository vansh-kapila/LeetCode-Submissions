class Solution {
public:
    vector<int> countBits(int n) {
        if(n==0)
        {
            vector<int> v;
            v.push_back(0);
            return v;
        }
        if(n==1)
        {
            vector<int> v;
            v.push_back(0);
            v.push_back(1);
            return v;
        }
        
        vector<int> dp(n+1);
        int pivot = 2;
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        for(int i=3;i<=n;i++)
        {
           if((i&(i-1))==0)
           {
               pivot = i;
               dp[pivot]=1;
               continue;
           }
           dp[i]=dp[pivot]+dp[i-pivot];
        }
        
        return dp;
    }
};