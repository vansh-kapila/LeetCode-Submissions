class Solution {
public:
    static bool comp(vector<int> &x,vector<int> &y)
    {
        return x[1]<y[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end(),comp);
        int ans = 1;
        int x = intervals[0][1];
        int j = 1;
        while(j<intervals.size())
        {
            if(intervals[j][0]>=x)
            {
                ans++;
                x = intervals[j][1];
                j++;
            }
            else
            {
                j++;
            }
        }
        return intervals.size()-ans;
    }
};