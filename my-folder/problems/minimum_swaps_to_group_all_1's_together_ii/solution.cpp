class Solution {
public:
    int minSwaps(vector<int>& nums) {
         int count = 0;
         for(auto i:nums)
         {
             count+=i;
         }
         int o = 0;
         int z = 0;
         for(int i=0;i<count;i++)
         {
             if(nums[i]==0)
             {
                 z++;
             }
             else
             {
                 o++;
             }
         }
         int ans = z;
         for(int i=count;i<2*nums.size();i++)
         {
             if(nums[(i-count)%nums.size()]==0)
             {
                 z--;
             }
             else
             {
                 o--;
             }
             if(nums[i%nums.size()]==0)
             {
                 z++; 
                 ans = min(ans,z);
             }
             else
             { 
                 o++;
                 ans = min(ans,z);
             }
         }
         return ans;
    }
};