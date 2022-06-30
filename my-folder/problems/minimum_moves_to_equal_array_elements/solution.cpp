class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0;
        sum = accumulate(nums.begin(),nums.end(),sum);
        return sum-*min_element(nums.begin(),nums.end())*nums.size();
    }
};