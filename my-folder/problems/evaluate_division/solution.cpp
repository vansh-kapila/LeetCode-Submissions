class Solution
{
    public:
        void dfs(string start, string end, double &val, bool &found, map<string, int> visited, map<pair<string, string>, double> mp, map< string, vector< string>> edges)
        {
            visited[start] = 1;

            if (found == true)
                return;
            for (auto child: edges[start])
            {
                if (visited[child] != 1)
                {
                    val *= mp[
                    {
                        start,
                        child
                    }];
                    if (end == child)
                    {
                        found = true;
                        return;
                    }
                    dfs(child, end, val, found,visited,mp,edges);
                    if (found == true)
                    {
                        return;
                    }
                    else
                    {
                        val /= mp[
                        {
                            start,
                            child
                        }];
                    }
                }
            }
        }
    vector<double> calcEquation(vector<vector < string>> &equations, vector< double > &values, vector< vector< string>> &queries)
    {

        map<string, int> visited;
        map<pair<string, string>, double> mp;
        map<string, vector < string>> edges;
        vector<double> ans;
        for (int i = 0; i < equations.size(); i++)
        {
            string u = equations[i][0];
            string v = equations[i][1];
            mp[
            {
                u,
                v
            }] = values[i];
            mp[
            {
                v,
                u
            }] = 1.0 / values[i];
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        for (int i = 0; i < queries.size(); i++)
        {
            string start = queries[i][0];
            string end = queries[i][1];
            if (edges.find(start) == edges.end() || edges.find(end) == edges.end())
            {
                ans.push_back(-1);
            }
            else
            {
                double val = 1;
                bool found = false;
                if (start == end)
                {
                    found = true;
                }
                else
                    dfs(start, end, val, found,visited, mp,edges);
                if (found == true)
                    ans.push_back(val);
                else
                    ans.push_back(-1);
            }
        }
        return ans;
    }
};