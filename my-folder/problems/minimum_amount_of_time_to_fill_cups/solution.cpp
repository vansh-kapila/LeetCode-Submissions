class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq;
        for(auto i:amount)
        {
            if(i==0)
            {
                continue;
            }
            pq.push(i);
        }
        int ans = 0;
        while(!pq.empty())
        {
            auto x = pq.top(); 
            pq.pop();
            if(!pq.empty())
            {
                auto y = pq.top();
                pq.pop();
                ans = ans + 1;
                if(x-1!=0)
                {
                    pq.push(x-1);
                }
                if(y-1!=0)
                {
                    pq.push(y-1);
                }
            }
            else
            {
                ans =  ans + 1;
                if(x-1!=0)
                {
                    pq.push(x-1);
                }
            }
        }
        return ans;
    }
};