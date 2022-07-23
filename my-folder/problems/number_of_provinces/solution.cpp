class Solution {
public:
    vector<bool> vis;
    void dfs(int root,vector<vector<int>> &v)
    {
        vis[root]=1;
        int j = 1;
        for(auto i:v[root-1])
        {
            if(i==1 and !vis[j])
            {
                dfs(j,v);
            }
            j++;
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        vis.resize(isConnected.size()+1,0);
        for(int i=0;i<isConnected.size();i++)
        {
            if(!vis[i+1])
            {
                dfs(i+1,isConnected);
                count++;
            }
        }
        return count;
    }
};