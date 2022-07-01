class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 0; 
        unordered_map<double,int> slope;
        for(int i=0;i<points.size();i++)
        {
            int count = 0;
            slope.clear();
            for(int j=0;j<points.size();j++)
            {
                 if(points[i][0]!=points[j][0])
                 {
                     slope[(double)(points[j][1]-points[i][1])/(double)(points[j][0]-points[i][0])]++;
                 }
            }
            for(auto i:slope)
            {
                ans = max(ans,i.second+1);
            }
        }
        
        map<int,int> parallely;
        for(auto i:points)
        {
            parallely[i[0]]++;
            ans = max(ans,parallely[i[0]]);
        }
        return ans;
    }
};