class Solution {
public:
    vector<bool> vis;
    long long count = 0;
    void dfs(vector<vector<int>> &edges,int i)
    {
        vis[i]=1;
        count++;
        for(auto j:edges[i])
        {
            if(!vis[j])
            {
                dfs(edges,j);
            }
        } 
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        int x = edges.size();
        vis.resize(n+1,0);
        vector<vector<int>> edges2(n);
        for(int i=0;i<x;i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            edges2[u].push_back(v);
            edges2[v].push_back(u);
        }
        swap(edges,edges2);
        vector<long long> v;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                count=0;
                dfs(edges,i);
                v.push_back(count);
            }
        }
        long long sum = 0;
        long long sum2 = 0;
        for(auto i:v)
        { 
            sum = sum+i;
            sum2 = sum2+i*i;
        }
        return (sum*sum-sum2)/2;
    }
};