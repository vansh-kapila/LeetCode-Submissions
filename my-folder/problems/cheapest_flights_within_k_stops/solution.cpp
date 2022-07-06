class Solution {
public:
    vector<vector<int>> graph;
    map<pair<int,int>,int> weight;
    vector<bool> vis; 
    int dfs(int src,int dest,int k,vector<vector<int>> &dp)
    { 
        if(src==dest)
        {
            return 0;
        }
        if(dp[src][k+1]!=-1)
        {
            return dp[src][k+1];
        } 
        long long ans = INT_MAX;
        for(auto i:graph[src])
        {
            if(k>=0)
            {
                ans = min(ans,(long long)weight[{src,i}]+dfs(i,dest,k-1,dp));
            }
        }  
        return dp[src][k+1]=ans;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<int>> dp(n+1,vector<int>(k+2,-1));
        graph.resize(n);
        vis.resize(n,0);
        for(auto i:flights)
        {
            graph[i[0]].push_back(i[1]);
            weight[{i[0],i[1]}]=i[2];
        }
        int price = dfs(src,dst,k,dp);
        if(price==INT_MAX)
        {
            return -1;
        }
        return price;
    }
};