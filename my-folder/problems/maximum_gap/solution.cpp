class Solution {
public:
    int maximumGap(vector<int>& nums) {
        priority_queue<int> pq;
        
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
        }
        
        int maxx = 0;
        int ans = 0;
        while(!pq.empty())
        {   ans = pq.top();
            pq.pop();
            maxx = max(ans-pq.top(),maxx);
        }
        
        return maxx;
    }
};