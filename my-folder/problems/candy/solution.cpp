class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> rightstreak(ratings.size(),1);
        vector<int> leftstreak(ratings.size(),1);
        leftstreak[0]=1;
        for(int i=1;i<ratings.size();i++)
        {
            if(ratings[i]>ratings[i-1])
            {
                leftstreak[i]=leftstreak[i-1]+1;
            }
            else
            {
                leftstreak[i]=1;
            }
        }
        
        for(int i=ratings.size()-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
            {
                rightstreak[i]=rightstreak[i+1]+1;
            }
            else
            {
                rightstreak[i]=1;
            }
        }
        
        int sum = 0;
        for(int i=0;i<ratings.size();i++)
        {
            sum = sum + max(rightstreak[i],leftstreak[i]);
        }
        return sum;
    }
};