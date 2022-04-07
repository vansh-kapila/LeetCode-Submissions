class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> v;
        for(int i=0;i<points.size();i++)
        {
            v.push_back(points[i][0]);
        }
        int ans = 0;
        sort(v.begin(),v.end());
        for(int i=0;i<v.size()-1;i++)
        {
            ans = max(ans,v[i+1]-v[i]);
        }
        return ans;
    }
};