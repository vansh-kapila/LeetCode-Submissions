class Solution {
public:
    int solve(vector<int> &cookies,vector<int> &nums,int n)
    {
        if(n==0)
        {   
           int x = 0;
           for(auto i:nums)
           {
               x = max(x,i);
           }
           return x;
        } 
        int ans = 1e9+7;
        for(int i=nums.size()-1;i>=0;i--)
        {   
            nums[i]=nums[i]+cookies[n-1];
            ans = min(ans,solve(cookies,nums,n-1));
            nums[i]-=cookies[n-1];
        }
        return ans;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        
        vector<int> nums(k,0); 
        return solve(cookies,nums,cookies.size());
    }
};