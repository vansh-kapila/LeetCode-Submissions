class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        sum = accumulate(nums.begin(),nums.end(),sum);
        return n*(n+1)/2-sum;
    }
};