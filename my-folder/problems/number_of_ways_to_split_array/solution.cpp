class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = 0;
        sum  = accumulate(nums.begin(),nums.end(),sum);
        long long x = 0;
        int count = 0;
        for(int i=0;i<nums.size()-1;i++)
        {
            x+=(long long)nums[i];
            if(x>=sum-x)
            {
                count++;
            }
        }
        return count;
    }
};