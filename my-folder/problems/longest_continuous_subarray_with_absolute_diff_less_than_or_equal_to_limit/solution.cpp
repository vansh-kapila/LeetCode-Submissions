class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> ms;
        int j = 0;
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            ms.insert(nums[i]);
            while(ms.empty() or *ms.rbegin()-*ms.begin()>limit)
            {
                ms.erase(ms.find(nums[j]));
                j++;
            }
            ans = max(ans,i-j+1);
        }
        return ans;
    }
};