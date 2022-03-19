class Solution {
public: 
    
    int solve(string &v,int x,int l,int i,vector<vector<int>> &dp)
    {  
        if(i<0)
        {
            return 0;
        }
        if(dp[x][i]!=-1)
        {
            return dp[x][i];
        }
        int inc = 100000007;
        if(v[i]=='1')
        {
         if(x>0)
         {  
           inc = solve(v,x-1,l,i-l,dp);
         }
         int exc = 1+solve(v,x,l,i-1,dp);
         dp[x][i] = min(inc,exc);
         return dp[x][i];
        }
        
        int z = solve(v,x,l,i-1,dp);
        dp[x][i] = z;
        return dp[x][i];
    }
    
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
       
        vector<vector<int>> dp(numCarpets+1);
        for(int i=0;i<numCarpets+1;i++)
        {
            for(int j=0;j<floor.length()+1;j++)
            {
                dp[i].push_back(-1);
            }
        }
        
        int y = solve(floor,numCarpets,carpetLen,floor.length(),dp); 
        return y;
    }
};