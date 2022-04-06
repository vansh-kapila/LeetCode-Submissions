class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end(),greater<int>());
        int sum = 0;
        for(int i = 0;i<cost.size();i++)
        {
            if(i%3==2)
            {
                continue;
            }
            sum+=cost[i];
        }
        return sum;
    }
};