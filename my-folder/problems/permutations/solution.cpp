class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<int> v(nums); 
        vector<vector<int>> ans;
        ans.push_back(nums);
        while(next_permutation(v.begin(),v.end()))
        {
           ans.push_back(v);
        }
        return ans;
    }
};