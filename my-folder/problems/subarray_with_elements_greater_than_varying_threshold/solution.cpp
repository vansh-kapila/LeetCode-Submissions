class Solution {
public: 
    int validSubarraySize(vector<int>& nums, int threshold) {
        vector<int> nextsmaller(nums.size(),nums.size());
        vector<int> prevsmaller(nums.size(),-1);
        stack<pair<int,int>> st;
        for(int i=0;i<nums.size();i++)
        {
            while(!st.empty() and st.top().first>=nums[i])
            { 
                st.pop();
            }
            if(!st.empty())
            {
              prevsmaller[i]=st.top().second;
            }
            st.push({nums[i],i});
        }
        while(!st.empty())
        {
            st.pop();
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
            while(!st.empty() and st.top().first>=nums[i])
            { 
                st.pop();
            }
            if(!st.empty())
            {
              nextsmaller[i]=st.top().second;
            }
            st.push({nums[i],i});
        }
        int ans = -1;
        for(int i=0;i<nums.size();i++)
        { 
            if((long long)(nextsmaller[i]-prevsmaller[i]-1)*nums[i]>threshold)
            {
                return nextsmaller[i]-prevsmaller[i]-1;
            }
        }
        return -1;
    }
};