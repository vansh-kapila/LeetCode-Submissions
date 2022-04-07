class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        map<pair<int,int>,int> m;
        int ans = 100000007;
        for(int i=0;i<points.size();i++)
        {
            m[{points[i][0],points[i][1]}]++;
        }
        for(int i=0;i<points.size();i++)
        {
            for(int j=i+1;j<points.size();j++)
            {
                if(points[i][0]!=points[j][0] and points[i][1]!=points[j][1])
                {   
                    if(m.find({points[i][0],points[j][1]})!=m.end() and m.find({points[j][0],points[i][1]})!=m.end())
                    {   
                        ans = min(ans,abs(points[i][1]-points[j][1])*abs(points[i][0]-points[j][0]));
                    }
                }
            }
        }
        if(ans>=100000007)
        {
            return 0;
        }
        return ans;
    }
};