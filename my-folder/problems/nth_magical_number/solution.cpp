class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        int l = 0;
        long long r = INT_MAX;
        while(l<r)
        {
            long long mid = (l+r)/2;
            long long x = mid*a;
            long long y = x/a+x/b-(x*__gcd(a,b))/(a*b);
            if(y==n)
            {
                return x%1000000007;
            }
            else if(y<n)
            {
                l = mid+1;
            }
            else
            {
                r=mid;
            }
        }
        l = 0;
        r = INT_MAX;
        while(l<r)
        {
            long long mid = (l+r)/2;
            long long x = mid*b;
            long long y = x/a+x/b-(x*__gcd(a,b))/(a*b);
            if(y==n)
            {
                return x%1000000007;
            }
            else if(y<n)
            {
                l=mid+1;
            }
            else
            {
                r=mid;
            }
        }
        return -1;
    }
};