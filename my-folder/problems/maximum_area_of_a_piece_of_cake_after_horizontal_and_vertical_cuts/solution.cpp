class Solution {
public:
    const long long mod = 1e9+7;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        long long x = 0;long long y = 0;
        for(int i=1;i<horizontalCuts.size();i++)
        {
            x = max(x,(long long)horizontalCuts[i]-horizontalCuts[i-1]); 
        }
        for(int i=1;i<verticalCuts.size();i++)
        {
            y = max(y,(long long)verticalCuts[i]-verticalCuts[i-1]); 
        }
        return (x*y)%mod;
    }
};