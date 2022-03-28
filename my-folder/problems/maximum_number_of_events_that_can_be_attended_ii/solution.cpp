class Solution {
public: 

    int solve(vector<vector<int>> &events,int k,int i,vector<vector<int>> &dp)
    {
        if(i==events.size() or k==0)
        {
            return 0;
        } 
        if(dp[i][k]!=-1)
        {
            return dp[i][k];
        }
        int ans = 0; 
        int ind = -1;
        for(ind=i+1;ind<events.size();ind++)
        {
            if(events[ind][0]>events[i][1])
            {
                break;
            }
        }
        
        return dp[i][k]=max(solve(events,k,i+1,dp),events[i][2]+solve(events,k-1,ind,dp)); 
    }
    int maxValue(vector<vector<int>>& events, int k) 
    {
        sort(events.begin(),events.end());
        // for(int i=0;i<events.size();i++)
        // {
        //     for(auto j:events[i])
        //     {
        //        cout<<j<<endl;
        //     }
        // }
        int x= -1; 
        vector<vector<int>> dp;
        dp.resize(events.size()+1);
        for(int i=0;i<events.size();i++)
        {   
            for(int j=0;j<k+1;j++)
            {
              dp[i].push_back(-1);
            }
        }
        x = max(x,solve(events,k,0,dp)); 
        return x;
    }
};