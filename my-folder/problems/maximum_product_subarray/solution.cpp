class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int maxx = 1;
        int minn = 1;
        for(auto i:nums)
        {
            int y = maxx;
            maxx = max({i*maxx,i,i*minn});
            minn = min({i*y,i*minn,i});
            ans = max({ans,maxx,minn});
        }
        return ans;
    }
};