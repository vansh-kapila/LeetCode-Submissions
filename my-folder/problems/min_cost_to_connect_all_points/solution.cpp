class Solution
{
    public:
        int minCostConnectPoints(vector<vector < int>> &points)
        {
            int n = points.size();

            priority_queue<pair<int, int>, vector< pair<int, int>>, greater<pair<int, int>>> pq;
            unordered_set<int> vis;
            pq.push({ 0,
                0 });
            int ans = 0;
            int edge = 0;

            while (edge < n)
            {
                pair<int, int> x = pq.top();
                pq.pop();

                int weight = x.first;
                int y = x.second;

                if (vis.find(y) == vis.end())
                {  
                    vis.insert(y);
                    ans += weight;
                    edge++;

                    for (int i = 0; i < n; ++i)
                    {
                        if (vis.find(i) == vis.end())
                        {
                            int nextWeight = abs(points[y][0] - points[i][0]) +
                                abs(points[y][1] - points[i][1]);

                            pq.push({ nextWeight,
                                i });
                        }
                    }
                }
            }

            return ans;
        }
};