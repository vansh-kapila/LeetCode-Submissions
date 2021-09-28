class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end(),greater<int>());
        int ans = 0;
        int count = 0;
        for(int i=1;count<piles.size()/3;i+=2)
        {   
            count++;
            ans+=piles[i];
        }
        
        return ans;
    }
};