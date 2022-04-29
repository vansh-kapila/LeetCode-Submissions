class Solution
{
    public:
        vector<int> store;
    vector<bool> vis;
    bool dfs(int x, int col, vector<vector < int>> &graph)
    {
        vis[x] = 1;
        store[x] = col;
        for (auto i: graph[x])
        {
            if (vis[i] == 0 and!dfs(i, col ^ 1, graph))
            {
                return 0;
            }
            if (store[x] == store[i])
            {
                return 0;
            }
        }
        return 1;
    }
    bool isBipartite(vector<vector < int>> &graph)
    {
        store.resize(graph.size());
        vis.resize(graph.size());
        for (int i = 0; i < graph.size(); i++)
        {
            if (!vis[i] and !dfs(i, 0, graph))
            {
                return 0;
            }
        }
        return 1;
    }
};