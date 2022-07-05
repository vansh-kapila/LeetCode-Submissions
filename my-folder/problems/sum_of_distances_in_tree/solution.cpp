class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> vis;
    vector<int> dp;
    vector<int> children; 
    int storechildren(int root)
    {
        vis[root]=1;
        int ans = 0;
        for(auto i:graph[root])
        {
            if(!vis[i])
            {
                children[i] = storechildren(i);
                ans = ans + children[i];
            }
            else
            {
                ans = ans + children[i];
            }
        }
        return ans+1;
    }
    int dfs(int root,int distance)
    { 
        vis[root]=1;
        int ans = 0;
        for(auto i:graph[root])
        {
            if(!vis[i])
            { 
                ans = ans + distance + dfs(i,distance+1);
            } 
        }
        return ans;
    }
    void dfs2(int root)
    {
        vis[root]=1; 
        for(auto i:graph[root])
        {
            if(!vis[i])
            {
                dp[i]=dp[root]+graph.size()-2*children[i];
                dfs2(i);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        dp.resize(n,0);
        vis.resize(n,0);
        children.resize(n,0);
        for(auto i:edges)
        {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        storechildren(0);
        vis.clear();
        vis.resize(n,0); 
        for(int i=0;i<n;i++)
        {
            dp[0]=dfs(i,1);
            vis.clear();
            vis.resize(n,0);  
            break;
        } 
        dfs2(0);
        return dp;
    }
};