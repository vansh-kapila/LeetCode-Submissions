class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int i = max_element(nums.begin(),nums.end())-nums.begin();
        int maxx = nums[i];
        nums[i]=-1;
        int sec = *max_element(nums.begin(),nums.end());
        if(maxx>=2*sec)
        {
            return i;
        }
        return -1;
    }
};