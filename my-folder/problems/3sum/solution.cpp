class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        set<vector<int>> v;
        int n = nums.size(); 
        sort(nums.begin(),nums.end());
        for(int i=2;i<n;i++)
        {
            int l = 0;
            int r = i-1;
            if(nums[l]+nums[l+1]+nums[i]>0)
            {
                continue;
            }
            if(nums[r-1]+nums[r]+nums[i]<0)
            {
                continue;
            }
            while(l<r)
            {  
                if(nums[l]+nums[r]+nums[i]==0)
                {
                    v.insert({nums[l],nums[r],nums[i]}); 
                    while(l<nums.size()-1 and nums[l]==nums[l+1] and l<r){
                    l++;}
                    while(r>=1 and nums[r]==nums[r-1] and l<r){
                    r--;}
                    l++;
                    r--;
                }
                else if(nums[l]+nums[r]+nums[i]>0)
                {
                    r--;
                }
                else
                {
                    l++;
                }       
            }
        }
        vector<vector<int>> vv;
        auto it = v.begin();
        for(int i=0;i<v.size();i++)
        {   
            vector<int> point = *it;
            vv.push_back(point);
            it++;
        }
        return vv;
    }
};