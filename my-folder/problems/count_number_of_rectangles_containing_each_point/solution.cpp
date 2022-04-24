class Solution {
public: 
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
         
         vector<vector<int>> v(101);
         for(int i=0;i<rectangles.size();i++)
         {
             v[rectangles[i][1]].push_back(rectangles[i][0]);
         }
        for(int i=0;i<v.size();i++)
        {   
            if(!v[i].empty()){
            sort(v[i].begin(),v[i].end());}
        }
        int ans = 0;
        vector<int> ret;
        for(int i=0;i<points.size();i++)
        {   
            ans = 0;
            for(int j=0;j<v.size();j++)
            {   
                if(j>=points[i][1])
                {
                 int x = lower_bound(v[j].begin(),v[j].end(),points[i][0])-v[j].begin(); 
                 ans+=(v[j].size()-x); 
                }
            }
            ret.push_back(ans);
        }   
        
        return ret;
    }
};