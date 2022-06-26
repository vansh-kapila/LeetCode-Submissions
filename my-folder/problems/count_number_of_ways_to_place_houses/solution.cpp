class Solution {
public:
    const long long mod = 1e9+7;
    int countHousePlacements(int n) {
         long long x = 1;
         long long y = 2;
         for(int i=1;i<n;i++)
         { 
             long long z = y;
             y = (y+x)%mod;
             x = z%mod;
         }
        return (y*y)%mod;
    }
};