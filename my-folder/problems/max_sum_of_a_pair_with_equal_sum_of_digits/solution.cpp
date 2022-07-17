class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<vector<int>> v(100);
        for(auto i:nums)
        {
            int j = i;
            int sum = 0;
            while(j!=0)
            {
                sum = sum + j%10;
                j/=10;
            }
            v[sum].push_back(i);
        }
        
        for(auto &i:v)
        {
            sort(i.begin(),i.end());
        }
        int ans = -1;
        for(auto &i:v)
        {
            if(i.size()>=2)
            {
                ans = max(ans,i[i.size()-1]+i[i.size()-2]);
            }
        }
        return ans;
    }
};