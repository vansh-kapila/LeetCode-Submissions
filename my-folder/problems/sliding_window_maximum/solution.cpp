class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>> dq;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            while(!dq.empty() and dq.front().first<nums[i])
            {
                dq.pop_front();
            }
            while(!dq.empty() and dq.back().second<=i-k)
            {
                dq.pop_back();
            }
            dq.push_front({nums[i],i});
            if(i>=k-1)
            {
                ans.push_back(dq.back().first);
            }
        }
        return ans;
    }
};