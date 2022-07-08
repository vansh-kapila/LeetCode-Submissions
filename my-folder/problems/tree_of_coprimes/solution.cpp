class Solution {
public: 
    vector<vector<int>> graph;
    vector<int> ans;
    vector<int> vis;
    void dfs(int root,int level,vector<int> &nums,map<int,vector<pair<int,int>>> &mp)
    {
        vis[root]=1; 
        int level2 = -1; 
        for(auto &i:mp)
        { 
            if(!i.second.empty() and i.second.back().second>level2 and __gcd(nums[root],i.first)==1)
            {  
                ans[root] = i.second.back().first;
                level2 = i.second.back().second;
            }
        } 
        int x = nums[root];
        mp[x].push_back({root,level});
        for(auto i:graph[root])
        {
            if(!vis[i])
            {
                dfs(i,level+1,nums,mp);
            }
        }  
        mp[x].pop_back();
    }
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = edges.size()+1;
        ans.resize(n,-1); 
        vis.resize(n+1,0); 
        graph.resize(edges.size()+1);   
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        map<int,vector<pair<int,int>>> mp;
        dfs(0,0,nums,mp);
        return ans;
    }
};