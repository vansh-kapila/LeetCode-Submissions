class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        priority_queue<int> pq;
        
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
        } 
        int count=0;
        int ans=0;
        while(pq.empty()==false)
        {   int x = pq.top();
            pq.pop();
            if((x-pq.top())==1)
            {
                count++; 
            }
            ans = max(count,ans);
            if(x-pq.top()!=1 and x!=pq.top())
            {
             count=0;
            }
         }
        if(nums.size()==0)
        {
            return 0;
        }
        return ans+1;
    }
};