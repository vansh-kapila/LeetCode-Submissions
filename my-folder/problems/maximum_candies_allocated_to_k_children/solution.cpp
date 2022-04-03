class Solution {
public:
    int maximumCandies(vector<int>& nums, long long k) {
          
        int l = 0;
        int r = 1000000007;
        int ret = 0;
        while(l<r)
        {
            int mid = (l+r)/2;
            if(mid==0)
            {
                break;
            }
            bool ans = false;
            long long count = 0;
            for(int i=0;i<nums.size();i++)
            {
                count = count+(nums[i]/mid);
            } 
            if(count>=k)
            {
                ans = true;
            }
            if(ans)
            {
                l = mid+1;
                ret = max(ret,mid);
            }
            else
            {
                r = mid;
            }
        }
        return ret;
    }
};