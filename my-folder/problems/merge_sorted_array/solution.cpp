class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> v;
        int x = 0;
        int y = 0;
        
        while(x<m and y<n)
        {
            if(nums1[x]<=nums2[y])
            {
                v.push_back(nums1[x]);
                x++;
            }
            else
            {
                v.push_back(nums2[y]);
                y++;
            }
        }
        
         while(x<m)
        { 
                v.push_back(nums1[x]);
                x++;
           
        }
        
          while(y<n)
        { 
                v.push_back(nums2[y]);
                y++;
           
        }
        
        for(int i=0;i<v.size();i++)
        {
            nums1[i]=v[i];
        }
    }
};