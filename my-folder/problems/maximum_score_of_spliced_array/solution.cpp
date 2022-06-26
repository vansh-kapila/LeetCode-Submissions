class Solution {
public:
    int subarray(vector<int> &v)
    { 
      int max_so_far = 0, max_ending_here = 0;
 
     for (int i = 0; i < v.size(); i++)
     {
         max_ending_here = max_ending_here + v[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
     }
     return max_so_far; 
    }
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> v1;
        vector<int> v2;
        
        for(int i=0;i<nums1.size();i++)
        {
            v1.push_back(nums1[i]-nums2[i]);
        }
        
        for(int i=0;i<nums1.size();i++)
        {
            v2.push_back(nums2[i]-nums1[i]);
        }
        int sum1 = 0,sum2 = 0;
        sum1 = accumulate(nums1.begin(),nums1.end(),sum1);
        sum2 = accumulate(nums2.begin(),nums2.end(),sum2);
        return max({sum2+subarray(v1),sum1+subarray(v2)});
    }
};