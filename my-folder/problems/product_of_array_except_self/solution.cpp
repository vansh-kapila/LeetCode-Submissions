class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> suff(n+1,1);
        vector<int> pre(n+1,1);
        for(int i=0;i<nums.size();i++)
        {
            pre[i+1]=pre[i]*nums[i];
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
            suff[i]=suff[i+1]*nums[i];
        }
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            ans[i]=pre[i]*suff[i+1];
        }
        return ans;
    }
};