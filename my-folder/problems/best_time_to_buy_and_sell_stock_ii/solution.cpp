class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int low = prices[0];
        int n = prices.size();
        
        for(int i=1;i<n;i++)
        {
            if(prices[i]<low)
            {
                low = prices[i];
            }
            else
            {
                profit+=prices[i]-low;
                low = prices[i];
            }
        }
        return profit;
    }
};