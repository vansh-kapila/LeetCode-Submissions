class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto i:nums)
        {
            pq.push(i);
        }
        int mod = 1e9+7;
        while(k--)
        {
            int x = pq.top();
            x++;
            pq.pop();
            pq.push(x);
        }
        long long ans = 1;
        while(!pq.empty())
        {
            ans = (ans*pq.top())%mod;
            pq.pop();
        }
        return ans;
    }
};