class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int kk;
    KthLargest(int k,vector<int>& nums) {
        for(auto i:nums)
            {
            pq.push(i);
            }
        kk=k;
    }
    
    int add(int val) {
        pq.push(val);
        int ans=0;
        while(pq.size()>kk)
            {
              pq.pop();
            }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */