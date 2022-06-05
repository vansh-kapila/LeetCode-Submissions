class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        
        while(nums.size()>1)
        {
            vector<int> nums2;
            for(int i=0;i<nums.size()/2;i++)
                {   if(i%2==0){
                    nums2.push_back(min(nums[2*i],nums[2*i+1]));
                    }
                 if(i%2==1){
                    nums2.push_back(max(nums[2*i],nums[2*i+1]));
                    }
                }
            nums = nums2;
        }
        return nums.back();
    }
};