class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        int pre[n];
        pre[0]= nums[0];
       
        for(int i=1;i<n;i++)
        {
            pre[i]=pre[i-1]+nums[i];
        }
        if(pre[n-1]-pre[0]==0)
        {
            return 0;
        }
        if(n==1)
        {
            return 0;
        }
       
        
        for(int i=1;i<n-1;i++)
        {
            if(pre[i-1]==pre[n-1]-pre[i])
            {
                return i;
            }
        }
         if(pre[n-2]==0)
        {
            return n-1;
        }
        return -1;
    }
};