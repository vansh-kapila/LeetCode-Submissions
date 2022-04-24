class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        
        int count = 0;
        set<pair<int,int>> s;
        for(int k=0;k<circles.size();k++){
        for(int i=circles[k][0]-circles[k][2];i<=circles[k][0]+circles[k][2];i++)
        {   
            for(int j=circles[k][1]-circles[k][2];j<=circles[k][1]+circles[k][2];j++)
            {   
                if(s.find({i,j})==s.end() and (i-circles[k][0])*(i-circles[k][0])+(j-circles[k][1])*(j-circles[k][1])<=circles[k][2]*circles[k][2])
                {
                    s.insert({i,j});  
                }
                if((i-circles[k][0])*(i-circles[k][0])+(j-circles[k][1])*(j-circles[k][1])>circles[k][2]*circles[k][2] and i>circles[k][0] and j>circles[k][1])
                {
                    break;
                }
            }
        }
        }
        
        return s.size();
    }
};