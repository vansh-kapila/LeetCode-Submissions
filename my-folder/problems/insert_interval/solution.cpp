class Solution
{
    public:

        vector<vector < int>> mergeintervals(vector<vector < int>> &intervals)
        {
            int i = 0;
            vector<vector < int>> merged;
            while (i < intervals.size())
            {
                int j = i + 1;
                int upperb = intervals[i][1];
                while (j < intervals.size() and intervals[j][0] <= upperb)
                {
                    upperb = max(upperb, intervals[j][1]);
                    j++;
                }
                intervals[i][1] = upperb;
                merged.push_back(intervals[i]);
                i = j;
            }
            return merged;
        }

    vector<vector < int>> insert(vector<vector < int>> &intervals, vector< int > &newInterval)
    {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        return mergeintervals(intervals);
    }
};