class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = INT_MAX;
        for(int i=1;i<=6;i++)
        {
            int counttops=0,countbottoms=0,count=0;
            for(int j=0;j<bottoms.size();j++)
            {
                if(tops[j]==i and bottoms[j]!=i)
                {
                    counttops++;
                }
                else if(bottoms[j]==i and tops[j]!=i)
                {
                    countbottoms++;
                }
                else if(tops[j]==i or bottoms[j]==i)
                {
                    count++;
                }
            }
            if(counttops+countbottoms+count==bottoms.size())
            {
                ans = min(ans,min(countbottoms,counttops));
            }
        }
        if(ans==INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};