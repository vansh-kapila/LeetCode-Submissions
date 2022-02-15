class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int x = 1;
        int ans = 0;
        int j = 0;
        for(int i=0;i<nums.size();i++)
        {
            x=x*nums[i]; 
            while(x>=k and j<=i)
            {                   
                x=x/nums[j]; 
                j++;
            } 
            ans=ans+(i-j)+1;
        } 
        
        return ans;
    }
};