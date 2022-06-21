class Solution
{
    public:
        int furthestBuilding(vector<int> &heights, int bricks, int ladders)
        {
            vector<pair<int, int>> v;
            for (int i = 0; i < heights.size() - 1; i++)
            {
                if (heights[i + 1] > heights[i])
                {
                    v.push_back({ heights[i + 1] - heights[i],
                        i });
                }
            }
            int ans = heights.size()-1;
            priority_queue<int,vector<int>,greater<int>> pq;
            for(auto i:v)
            {
                pq.push(i.first);
                if(pq.size()>ladders)
                {
                    if(!pq.empty() and bricks>=pq.top())
                    {
                        bricks-=pq.top();
                        pq.pop();
                    }
                    else
                    {
                        ans = i.second;
                        break;
                    }
                }
            }
            return ans;
        }
};