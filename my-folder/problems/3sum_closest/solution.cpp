class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
      
        int n = nums.size();
        int ans1 = -10000007;
        int ans2 = 10000007;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++)
        {
            int j = i+1;
            int k = n-1;
            
            while(j<k)
            {
                if((nums[i]+nums[j]+nums[k])<=target)
                {
                    ans1 = max(nums[i]+nums[j]+nums[k],ans1);
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }
        
        
        for(int i=0;i<n-2;i++)
        {
            int j = i+1;
            int k = n-1;
            
            while(j<k)
            {
                if(nums[i]+nums[j]+nums[k]>=target)
                {
                    ans2 = min(nums[i]+nums[j]+nums[k],ans2);
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
        if(abs(ans1-target)>=abs(ans2-target))
        {
            return ans2;
        }
        else
        {
            return ans1;
        }
    }
};