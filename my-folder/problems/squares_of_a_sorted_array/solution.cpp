class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> v;
        
        int l = 0;
        int r = nums.size()-1;
        while(l<=r)
        {
            if(nums[l]*nums[l]>=nums[r]*nums[r])
            {
                v.push_back(nums[l]*nums[l++]);
            }
            else
            {
                v.push_back(nums[r]*nums[r--]);
            }
        }
        reverse(v.begin(),v.end());
        return v;
    }
};