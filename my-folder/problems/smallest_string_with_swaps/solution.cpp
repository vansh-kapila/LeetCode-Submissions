class Solution {
public:
    vector<bool> vis;
    vector<vector<int>> edges;
    vector<int> track;
    void dfs(int x)
    {
        vis[x]=1;
        track.push_back(x);
        for(auto i:edges[x])
        {
            if(!vis[i])
            {
                dfs(i);
            }
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
         
        edges.resize(s.length());
        vis.resize(s.length());
        for(int i=0;i<s.length();i++)
        {
            vis[i]=0;
        }
        for(int i=0;i<pairs.size();i++)
        {
            edges[pairs[i][0]].push_back(pairs[i][1]);
            edges[pairs[i][1]].push_back(pairs[i][0]);
        }
        for(int i=0;i<s.length();i++)
        {
            if(!vis[i])
            {
                dfs(i);
                sort(track.begin(),track.end());
                string x;
                for(auto i:track)
                {
                    x.push_back(s[i]);
                }
                sort(x.begin(),x.end());
                int j = 0;
                for(auto i:track)
                {
                    s[i] = x[j++];
                }
                track.clear();
            }
        }
        
        return s;
    }
};