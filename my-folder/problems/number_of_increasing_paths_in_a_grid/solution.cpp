class Solution {
public:
    map<pair<int,int>,long long> vis;
    int solve(vector<vector<int>>&grid, int x, int y, int m, int n, int prev){
        if(x == m || x < 0 || y == n || y < 0)
            return 0;
        
        if(grid[x][y] <= prev)
            return 0;
        
        auto p = make_pair(x,y);
        if(vis.find(p) != vis.end()){
            return vis[p];
        }
        
        long long pth = 1;
        // up
        pth += solve(grid,x-1,y,m,n,grid[x][y]);
        
        // down
        pth +=  solve(grid,x+1,y,m,n,grid[x][y]);
        
        // left
        pth += solve(grid,x,y-1,m,n,grid[x][y]);
        
        // right
        pth += solve(grid,x,y+1,m,n,grid[x][y]);
        
        vis[p] = pth%mod;
        return pth%mod;
    }
    
    long long mod = pow(10,9) + 7;
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                auto p = make_pair(i,j);
                if(vis.find(p) != vis.end())
                    continue;
                solve(grid,i,j,m,n,-1);
            }
        }
        
        long long ans = 0;
        for(auto ele:vis)
            ans = (ans % mod + ele.second % mod) % mod; 
        return ans;
    }
};