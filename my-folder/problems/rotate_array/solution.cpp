class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        int n = nums.size();
        reverse(nums.begin(),nums.begin()+n-k);
        reverse(nums.begin()+n-k,nums.begin()+n);
        reverse(nums.begin(),nums.end());
    }
};