class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int x=0;
        if(nums.size()==1)
        {
            return 1;
        }
        int maxx = nums[0];
        for(int i=0;i<nums.size()-2;i++)
        {   
            maxx = max(maxx,nums[i]);
            if(maxx>(nums[i+2]))
            {
                x++;
                break;
            }
        } 
        return (x^1);
    }
};