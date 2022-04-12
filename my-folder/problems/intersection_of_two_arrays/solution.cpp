class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        set<int> ans;
        for(auto i:nums1)
        {
            s.insert(i);
        }
        for(auto i:nums2)
        {
            if(s.find(i)!=s.end())
            {
                ans.insert(i);
            }
        }
        vector<int> ret(ans.begin(),ans.end());
        return ret;
    }
};