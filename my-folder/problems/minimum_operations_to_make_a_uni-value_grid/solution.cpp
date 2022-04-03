class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> v;
        int ans = 0;
        vector<int> arr;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {    
                arr.push_back(grid[i][j]);
                v.push_back(grid[i][j]%x);
            }
        }
        sort(v.begin(),v.end());
        sort(arr.begin(),arr.end());
        if(v.back()!=v.front())
        {
            return -1;
        }
        int y = arr[(arr.size()-1)/2];
        for(int i=0;i<arr.size();i++)
        {
            ans = ans+abs(arr[i]-y);
        }
        return ans/x;
    }
};