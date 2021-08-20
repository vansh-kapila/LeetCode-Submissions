class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int price = 0;
        int minn=99999;
        for(int i=0;i<prices.size();i++)
        {
             minn = min(prices[i],minn);
             price = max(price,prices[i]-minn);
        }
        
        return price;
    }
};