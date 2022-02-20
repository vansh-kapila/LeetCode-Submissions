class Solution {
public: 
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>&b){ if (a[0] == b[0]) {
            return a[1] > b[1];
        }
            return a[0] < b[0]; 
        });
        int count = 1; 
        int end = intervals[0][1];
        for(int i=1;i<intervals.size();i++)
        {   
            if(end>=intervals[i][1])
            {
                continue;
            }
            else
            {
                count++; 
                end = intervals[i][1];
            }
        }
        return count;
    }
};