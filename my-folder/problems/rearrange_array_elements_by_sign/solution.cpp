class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        for(auto i:nums)
        {
            if(i>0)
            {
                pos.push_back(i);
            }
            else
            {
                neg.push_back(i);
            }
        }
        
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            if(i%2)
            {
                ans.push_back(neg[i/2]);
            }
            else
            {
                ans.push_back(pos[i/2]);
            }
        }
        return ans;
    }
};