class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int x = upper_bound(nums.begin(),nums.end(),target)-lower_bound(nums.begin(),nums.end(),target);
        vector<int> ans;
        int i = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        while(x--)
        {
            ans.push_back(i++);
        }
        return ans;
    }
};