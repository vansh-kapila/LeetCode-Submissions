class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {   int j = 1;
            while(i>0 and i<nums.size()-1 and nums[i+1]-nums[i]==nums[i]-nums[i-1])
            {    
                i++;
                ans = ans+(j++);
            }  
        }
        return ans;
    }
};