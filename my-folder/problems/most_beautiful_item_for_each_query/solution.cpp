class Solution
{
    public:
        static bool comp(vector<int> &x, vector<int> &y)
        {
            return x[0] < y[0];
        }
    vector<int> maximumBeauty(vector<vector < int>> &items, vector< int > &queries)
    {
        sort(items.begin(), items.end(), comp);
        vector<int> ans;
        vector<int> item;
        for (auto i: items)
        {
            item.push_back(i[0]);
        }
        for (int i = 1; i < items.size(); i++)
        {
            items[i][1] = max(items[i][1], items[i - 1][1]);
        }
        for (int i = 0; i < queries.size(); i++)
        {
            int it = upper_bound(item.begin(), item.end(), queries[i]) - item.begin();
            it--;
            if (it == -1)
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(items[it][1]);
            }
        }
        return ans;
    }
};