class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int,int> m;
        vector<int> v;
        for(int i=0;i<intervals.size();i++)
        {
            m[intervals[i][0]] = i;
            v.push_back(intervals[i][0]);
        }
        sort(v.begin(),v.end());
        vector<int> ans;
        for(int i=0;i<intervals.size();i++)
        {
            auto it = lower_bound(v.begin(),v.end(),intervals[i][1]);
            if(it==v.end())
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(m[*it]);
            }
        }
        return ans;
    }
};