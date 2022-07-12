class Solution {
public:
    int sidelength = 0;
    bool solve(vector<int> &matchsticks,vector<int> &v,int n)
    {
        if(n==0)
        {
             for(auto i:v)
             {
                 if(i!=sidelength)
                 {
                     return 0;
                 }
             }
             return 1;
        }
        if(matchsticks[n-1]>sidelength)
        {
            return 0;
        } 
        for(int i=0;i<4;i++)
        {
            if(v[i]+matchsticks[n-1]<=sidelength)
            {
                v[i]+=matchsticks[n-1];
                if(solve(matchsticks,v,n-1))
                {
                    return 1;
                }
                v[i]-=matchsticks[n-1];
            } 
        }
        return 0;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        sum = accumulate(matchsticks.begin(),matchsticks.end(),sum);
        if(sum%4)
        {
            return 0;
        }
        sort(matchsticks.begin(),matchsticks.end());
        for(auto i:matchsticks)
        {
            if(i>sum/4)
            {
                return 0;
            }
        }
        sidelength = sum/4;
        vector<int> v(4);
        return solve(matchsticks,v,matchsticks.size());
    }
};