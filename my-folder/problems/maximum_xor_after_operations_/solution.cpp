class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<30;i++)
        {
            int x = (1<<i);
            for(int j=0;j<nums.size();j++)
            {
                if((x&nums[j]))
                {
                    ans = ans+x;
                    break;
                }
            }
        }
        return ans;
    }
};