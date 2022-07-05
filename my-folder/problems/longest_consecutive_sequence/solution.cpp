class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int count = 0;
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            int j = nums[i];
            int count = 1;
            while(st.find(j+1)!=st.end())
            {
                count++; 
                st.erase(st.find(j+1));
                j++;
            }
            int y = nums[i];
            while(st.find(y-1)!=st.end())
            {
                count++; 
                st.erase(st.find(y-1));
                y--;
            }
            ans = max(ans,count);
        }
        return ans;
    }
};