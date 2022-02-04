class Solution {
public:
    vector<vector<int>> ans;
    
    void helper(vector<int> nums,int i,int n,vector<int> temp)
    {
        if(i==n)
        {   
            ans.push_back(temp);
            return;
        }
        
        helper(nums,i+1,n,temp);
        temp.push_back(nums[i]);
        helper(nums,i+1,n,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        int n = nums.size();
        helper(nums,0,n,temp);
        return ans;
    }
};