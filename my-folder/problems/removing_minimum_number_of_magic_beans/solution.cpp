class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(),beans.end());
        long long sum = 0;
        sum = accumulate(beans.begin(),beans.end(),sum); 
        long long ans = 1e18;
        for(int i=0;i<beans.size();i++)
        {   
            long long x = sum-beans[i]*(beans.size()-i);
            ans = min(ans,x); 
        }
        return ans;
    }
};