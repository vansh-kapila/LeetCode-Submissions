class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        	if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[sr].size() || image[sr][sc] == color)
		return image;
        queue<pair<int,int>> q;
        q.push({sr,sc});  
        int curr_col = image[sr][sc]; 
        while(!q.empty())
        {
            pair<int,int> it = q.front();
            q.pop();    
            image[it.first][it.second]=color; 
            if(it.first+1<image.size() and image[it.first+1][it.second]==curr_col)
            {
                q.push({it.first+1,it.second});
            }
            if(it.second+1<image[0].size() and image[it.first][it.second+1]==curr_col)
            {
                q.push({it.first,it.second+1});
            }
            if(it.first-1>=0 and image[it.first-1][it.second]==curr_col)
            {
                q.push({it.first-1,it.second});
            }
            if(it.second-1>=0 and image[it.first][it.second-1]==curr_col)
            {
                q.push({it.first,it.second-1});
            }  
        } 
        return image;
    }
};