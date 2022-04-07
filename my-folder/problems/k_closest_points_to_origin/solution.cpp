class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int,vector<int>>> store;
        for(int i=0;i<points.size();i++)
        {
            store.push_back({abs(points[i][0])*abs(points[i][0])+abs(points[i][1])*abs(points[i][1]),points[i]});
        }
        sort(store.begin(),store.end());
        vector<vector<int>> ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(store[i].second);
        }
        return ans;
    }
};