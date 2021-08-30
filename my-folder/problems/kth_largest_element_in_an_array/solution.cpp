class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int x = (n-k+1);
        priority_queue<int> pq;
        for(int i=0;i<n;i++)
        {
            pq.push(nums[i]);
        }
        k--;
        while(k--)
        {
            pq.pop();
        }
        return pq.top();   
    }
};