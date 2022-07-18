class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        for(int i=0;i<colors.length();i++)
        { 
            int maxx = neededTime[i];
            int sum = neededTime[i];
            while(i+1<colors.length() and colors[i]==colors[i+1])
            {
                sum+=neededTime[i+1];
                maxx = max(maxx,neededTime[i+1]);
                i++;
            }
            ans = ans + sum - maxx;
        }
        return ans;
    }
};