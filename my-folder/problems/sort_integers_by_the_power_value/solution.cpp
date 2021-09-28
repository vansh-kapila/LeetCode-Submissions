class Solution {
public:
    int steps(int n)
    {   int step = 0;
        while(n!=1)
        {
            if(n%2==1)
            {
                n=3*n+1;
            }
            else
            {
                n=n/2;
            }
            step++;
        }
     return step;
    }
    
    static bool second(pair<int,int> x,pair<int,int> y)
    {
        if(x.second<y.second)
        {
            return true;
        }
        if(x.second==y.second)
        {
            return x.first<y.first;
        }
        return false;
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> v;
        
        for(int i=lo;i<=hi;i++)
        {
            v.push_back(make_pair(i,steps(i)));
        }
        
        sort(v.begin(),v.end(),second);
        return v[k-1].first;
    }
};