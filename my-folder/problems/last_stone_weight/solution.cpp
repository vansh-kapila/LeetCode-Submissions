class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i=0;i<stones.size();i++)
        {
            pq.push(stones[i]);
        }
        while(pq.size()>=1)
        {   
            if(pq.size()==1 and pq.top()!=0)
            {
                return pq.top();
            }
            int x = pq.top();pq.pop();
            int y = pq.top();pq.pop();
            if(x!=y)
            {
                pq.push(x-y);
            }
        }
        return 0;
    }
};