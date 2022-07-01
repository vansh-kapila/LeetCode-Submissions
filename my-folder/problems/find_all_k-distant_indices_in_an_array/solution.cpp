class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> v;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==key)
            {
                v.push_back(i);
            }
        }
        
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<v.size();j++)
            {
                if(abs(i-v[j])<=k)
                {
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};