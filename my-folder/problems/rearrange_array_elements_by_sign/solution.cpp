class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> p;
        vector<int> e;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
            {
                p.push_back(nums[i]);
            }
            else
            {
                e.push_back(nums[i]);
            }
        }
        for(int i=0;i<p.size();i++)
        {
            ans.push_back(p[i]);
            ans.push_back(e[i]);
        }
        return ans;
    }
};