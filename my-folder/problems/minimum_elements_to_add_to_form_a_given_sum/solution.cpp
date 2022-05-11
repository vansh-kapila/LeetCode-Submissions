class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum = 0;
        sum = accumulate(nums.begin(),nums.end(),sum);
        return (abs(sum-goal)+limit-1)/limit;
    }
};