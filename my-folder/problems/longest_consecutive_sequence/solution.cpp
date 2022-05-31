class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashset(nums.begin(),nums.end());
        int ans = 0;
        for(auto i:hashset)
        {
            int count = 1;
            int j = i;
            while(hashset.find(j+1)!=hashset.end())
            {   
                hashset.erase(hashset.find(++j)); 
                count++;
            }
            j=i;
            while(hashset.find(j-1)!=hashset.end())
            {   
                hashset.erase(hashset.find(--j)); 
                count++;
            }
            ans = max(ans,count);
        }
        return ans;
    }
};