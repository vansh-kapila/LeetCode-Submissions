class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans = 0;
        for(int i=0;i<30;i++)
        {
            int x = 1<<i;
            int count = 0;
            for(int j=0;j<candidates.size();j++)
            {
                if((candidates[j]&x))
                {
                    count++;
                }
            }
            ans = max(ans,count);
        }
        return ans;
    }
};