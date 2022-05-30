class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> merged;
        int i = 0;
        while(i<intervals.size())
        {
            vector<int> v = intervals[i];
            int j = i;
            while(i<intervals.size() and v[1]>=intervals[i][0])
            {
                v[1]=max(v[1],intervals[i][1]);
                i++;
            }
            merged.push_back(v);
        }
        return merged;
    }
};