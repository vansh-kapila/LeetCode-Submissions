class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        set<int> x,y;
        for(int i=0;i<nums1.size();i++)
        {
            if(find(nums2.begin(),nums2.end(),nums1[i])==nums2.end())
            {
                x.insert(nums1[i]);
            }
        }
        for(int i=0;i<nums2.size();i++)
        {
            if(find(nums1.begin(),nums1.end(),nums2[i])==nums1.end())
            {
                y.insert(nums2[i]);
            }
        }
        vector<int> xx = {x.begin(),x.end()};
        vector<int> yy = {y.begin(),y.end()};
        return {xx,yy};
    }
};