class Solution {
public:
    int countElements(vector<int>& nums) { 
        sort(nums.begin(),nums.end());
        int minn = 0,maxx = 0;
        for(auto i:nums)
        {
            if(i==nums[0])
            {
                minn++;
            }
            else if(i==nums.back())
            {
                maxx++;
            }
        }
        return nums.size()-maxx-minn;
    }
};