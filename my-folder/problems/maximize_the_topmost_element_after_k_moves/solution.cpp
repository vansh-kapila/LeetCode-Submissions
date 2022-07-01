class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if(nums.size()==1 and 1==k%2)
        {
            return -1;
        }
        int max1 = -1;
        for(int i=0;i<nums.size();i++)
        { 
            if(i!=k-1 and i<=k)
            {
                max1 = max(max1,nums[i]);
            }
        }
        return max1;
    }
};