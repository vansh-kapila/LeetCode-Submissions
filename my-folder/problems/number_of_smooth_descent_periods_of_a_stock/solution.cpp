class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        long long count = 0;
        for(int i=0;i<prices.size()-1;i++)
        {
            if(prices[i]==prices[i+1]+1)
            {
                count++;
            }
            else
            {
                ans += count*(count+1)/2;
                count = 0;
            }
        }
        if(count>0)
        {
            ans = ans+(count)*(count+1)/2;
        }
        ans = ans+prices.size();
        return ans;
    }
};