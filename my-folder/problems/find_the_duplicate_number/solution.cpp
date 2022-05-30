class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       
        int f = nums[nums[0]];
        int s = nums[0];
        
        while(f!=s)
        {
            f = nums[nums[f]];
            s = nums[s];
        }
        
        f = 0; 
        while(f!=s)
        {
            s = nums[s];
            f = nums[f];
        }
        
        return f;
    }
};