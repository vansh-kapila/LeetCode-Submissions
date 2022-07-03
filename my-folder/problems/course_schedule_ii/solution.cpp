class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        map<int,int> deg;
        vector<vector<int>> graph(numCourses);
        for(auto i:prerequisites)
        {
            deg[i[0]]++;
            graph[i[1]].push_back(i[0]);
        }
        vector<bool> vis(numCourses,0);
        
        vector<int> v;
        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(!deg[i])
            {
                q.push(i);
                vis[i]=1;
                v.push_back(i);
            }
        }
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            for(auto i:graph[x])
            {
                deg[i]--;
                if(!deg[i])
                {
                    q.push(i);
                    v.push_back(i);
                }
            }
        }
        bool ans = 1;
        for(auto i:deg)
        {
            if(i.second)
            {
                ans = 0;
                break;
            }
        }
        if(!ans)
        {
            v.clear();
        }
        return v;
    }
};