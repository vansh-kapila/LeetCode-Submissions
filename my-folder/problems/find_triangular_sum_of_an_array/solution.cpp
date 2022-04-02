class Solution {
public:
    int triangularSum(vector<int>& nums) {
        
        while(1)
        {
            if(nums.size()==1)
            {
                return nums[0];
                break;
            }
            else
            {
                vector<int> v;
                for(int j=0;j<nums.size()-1;j++)
                {
                    v.push_back((nums[j+1]+nums[j])%10);
                }
                nums = v;
            }
        }
        return -1;
    }
};