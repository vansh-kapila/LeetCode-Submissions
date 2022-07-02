class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> vis(rooms.size(),0);
        queue<int> q;
        q.push(0);
        vis[0]=1;
        while(!q.empty())
        {
            int x = q.front(); 
            q.pop();
            
            for(auto i:rooms[x])
            {
                if(!vis[i])
                {
                    q.push(i);
                    vis[i]=1;
                }
            }
        }
        
        if(find(vis.begin(),vis.end(),0)==vis.end())
        {
            return 1;
        }
        return 0;
    }
};