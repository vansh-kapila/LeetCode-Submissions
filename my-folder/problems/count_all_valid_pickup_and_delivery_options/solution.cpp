class Solution {
public:
    int fact(int n)
    {
        long long x = 1;
        int y = n;
        for(int i=1;i<=2*n;i++)
        {
            if(i%2==0 and y>0)
            {
                x=(x*(i/2))%1000000007;
            }
            else
            {
                x=(x*i)%1000000007;
            }
        }
        int yy = x;
        return yy;
    }
    int countOrders(int n) {
        return fact(n);
    }
};