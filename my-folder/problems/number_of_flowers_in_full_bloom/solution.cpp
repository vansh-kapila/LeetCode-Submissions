class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        sort(flowers.begin(),flowers.end());
        vector<int> x;
        vector<int> y;
        for(int i=0;i<flowers.size();i++)
        {
            x.push_back(flowers[i][0]);
            y.push_back(flowers[i][1]);
        }
        
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        
        vector<int> ans;
        for(auto i:persons)
        {
            int xx = lower_bound(x.begin(),x.end(),i+1)-x.begin();
                int yy = lower_bound(y.begin(),y.end(),i)-y.begin();
            ans.push_back(xx-yy);
        }
        return ans;
    }
};