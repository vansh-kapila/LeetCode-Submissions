class Solution {
public:
    vector<bool> vis;
    void dfs(vector<vector<int>> &edges,int x)
    {
         vis[x]=1;
         for(auto i:edges[x])
         {
             if(!vis[i])
             {
                 dfs(edges,i);
             }
         }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        vis.resize(edges.size()+4);
        vector<int> ret;
        vector<vector<int>> edge(edges.size()+2);
        for(auto i:edges)
        {
            edge[i[0]].push_back(i[1]);
            edge[i[1]].push_back(i[0]);
        }
        for(int i=0;i<edges.size();i++)
        {
            ans = edges[i]; 
            edge[edges[i][0]].erase(find(edge[edges[i][0]].begin(),edge[edges[i][0]].end(),edges[i][1]));
            edge[edges[i][1]].erase(find(edge[edges[i][1]].begin(),edge[edges[i][1]].end(),edges[i][0]));
            for(int j=0;j<vis.size();j++)
            {
                vis[j]=0;
            }
            dfs(edge,1);
            bool connected = 1;
            for(int j=1;j<=edges.size();j++)
            {
                if(vis[j]==0)
                {
                    connected = 0;
                    break;
                }
            }
            if(connected)
            {
                ret = ans;
            }
            edge[edges[i][0]].push_back(edges[i][1]);
            edge[edges[i][1]].push_back(edges[i][0]);
        }
        return ret;
    }
};