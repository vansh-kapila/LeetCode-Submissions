class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        vector<int> ans;
        int sum = 0;
        sum = accumulate(nums.begin(),nums.end(),sum);
        for(int i=0;i<nums.size();i++)
        {
            sum=sum-2*nums[i];
            ans.push_back(nums[i]);
            if(sum<0)
            {
                return ans;
            }
        }
        return ans;
    }
};