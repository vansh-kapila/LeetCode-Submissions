class Solution {
public:
    double power(double x,int n)
    {   if(n==0)
        {
           return 1;
        }
        if(n%2==0)
        {
            return power(x*x,n/2);
        }
        else
        {
            return power(x*x,n/2)*x;
        }
    }
    
    double myPow(double x, int n) {
        double ans=1;
        
        ans = power(x,abs(n));
        if(n<0)
        {
            return 1/ans;
        } 
        return ans;
    }
};