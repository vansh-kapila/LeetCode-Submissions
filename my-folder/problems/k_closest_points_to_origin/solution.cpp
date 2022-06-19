class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int,vector<int>>> v;
        
        for(auto i:points)
        {
            v.push_back({i[0]*i[0]+i[1]*i[1],i});
        }
        
        sort(v.begin(),v.end());
        
        vector<vector<int>> ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(v[i].second);
        }
        return ans;
    }
};