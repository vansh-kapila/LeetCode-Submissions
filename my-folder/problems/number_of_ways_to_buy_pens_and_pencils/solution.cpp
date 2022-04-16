class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans=total/cost2+1;
        for(int i=1;i<=total/cost1;i++)
        {
            ans = ans+(total-cost1*i)/cost2+1;
        }
        return ans;
    }
};