class Solution {
public:
    int reverse(int x) {
        long long a=0,flag=0; 
        while(x!=0)
        {
            a=a*10+x%10;
            x=x/10;
        }
         return (a<INT_MIN || a>INT_MAX) ? 0 : a;
    }
};