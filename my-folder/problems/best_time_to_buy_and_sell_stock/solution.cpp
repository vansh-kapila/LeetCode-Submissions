class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mins = prices[0];
        int ans=0;
        for(int i=0;i<prices.size()-1;i++)
        {
            if(prices[i]>prices[i+1])
            {
                mins=min(mins,prices[i+1]);
            }
            
            
            ans = max(prices[i+1]-mins,ans);
            
            
        }
        
        return ans;
    }
};