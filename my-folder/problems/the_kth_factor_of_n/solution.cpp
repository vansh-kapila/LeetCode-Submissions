class Solution {
public:
    int kthFactor(int n, int k) {
        set<int> s;
        for(int i=1;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                s.insert(i);
                s.insert(n/i);
            }
        }
        auto it = s.begin(); 
        if(s.size()<k)
        {
            return -1;
        } 
        it = next(it,k-1);
        return *it;
    }
};