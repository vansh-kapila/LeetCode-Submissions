class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> s(nums1.begin(),nums1.end());
        vector<int> ans;
        for(int i=0;i<nums2.size();i++)
        {
            auto it = s.upper_bound(nums2[i]);
            if(it!=s.end())
            {
                ans.push_back(*it);
                s.erase(it);
            }
            else
            {
                ans.push_back(*s.begin());
                s.erase(s.begin());
            }
        }
        return ans;
    }
};