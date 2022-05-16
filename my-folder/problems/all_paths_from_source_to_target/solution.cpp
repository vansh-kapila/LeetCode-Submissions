class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int x,vector<vector<int>> &graph,vector<int> v)
    {  
       v.push_back(x);
       if(x==graph.size()-1)
       {
           ans.push_back(v);
           return;
       }
       for(auto i:graph[x])
       {  
           dfs(i,graph,v);
       }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> v;
        dfs(0,graph,v);
        return ans;
    }
};