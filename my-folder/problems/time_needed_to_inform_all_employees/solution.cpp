class Solution {
public:
    vector<vector<int>> edges;
    vector<bool> vis;
    int dfs(int root,vector<int> &v)
    {
        vis[root]=1;
        int ans = 0;
        for(auto i:edges[root])
        {
            if(!vis[i])
            {
                ans = max(ans,dfs(i,v));
            }
        }
        return ans+v[root];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        edges.resize(n);
        for(int i = 0;i<manager.size();i++)
        {
            if(manager[i]!=-1)
            {
                edges[i].push_back(manager[i]);
                edges[manager[i]].push_back(i);
            }
        }
        
        vis.resize(n,0);
        return dfs(headID,informTime);
    }
};