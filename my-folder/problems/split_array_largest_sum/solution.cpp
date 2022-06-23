class Solution {
public:
    
    bool check(vector<int> &nums,int mid,int m)
    {
        int x = 0;
        int count = 1;
        for(int i=0;i<nums.size();i++)
        {
            if(x+nums[i]>mid)
            {
                x = nums[i];
                count++;
            }
            else
            {
                x=x+nums[i];
            }
        }
        return count<=m;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int l = *max_element(nums.begin(),nums.end());
        int r = 0;
        r = accumulate(nums.begin(),nums.end(),r);
        
        while(l<r)
        {
            int mid = (l+r)/2;
            if(check(nums,mid,m))
            {
                r = mid;
            }
            else
            {
                l = mid+1;
            }
        }
        
        return r;
    }
};