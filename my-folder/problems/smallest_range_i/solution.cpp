class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int n = nums.size();
        int s = INT_MAX;
        int m = INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            s=min(s,nums[i]);
            m=max(m,nums[i]);
        }
        
        return max(m-s-2*k,0);
    }
};