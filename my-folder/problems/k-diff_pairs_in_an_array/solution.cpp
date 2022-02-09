class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        if(nums.size()==1)
        {
            return 0;
        }
        unordered_map<int,int> m;
        int count0 = 0;
        for(int i=0;i<nums.size();i++)
        {   
             m[nums[i]]++;
             if(m[nums[i]]>=2)
             {
                count0++;
                m[nums[i]]=-1000000007;
             }
        }
        if(k==0)
        {
            return count0;
        }
        int count = 0;
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++)s.insert(nums[i]);
        for(auto i:s)
        {
            if(s.find(i+k)!=s.end())
            {
                count++;
            }
        }
        
        return count;
    }
};