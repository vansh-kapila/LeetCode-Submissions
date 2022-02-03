class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
          map<int,int> m;
        for(int i=0;i<nums4.size();i++)
        {   
            for(int j=0;j<nums3.size();j++)
        {
            m[nums4[i]+nums3[j]]++;
        }
        }
        int ans = 0;
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                 if(m.find(-1*(nums1[i]+nums2[j]))!=m.end())
                    {
                        ans+=m[-1*(nums1[i]+nums2[j])];
                    }
                
            }
        }
        
        return ans;
    }
};