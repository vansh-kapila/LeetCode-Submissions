class Solution {
public:
    bool isHappy(int n) {
        
        while(n/10!=0)
        {
            int ans = 0;
            while(n!=0)
            {
                ans+=(n%10)*(n%10);
                n=n/10;
            }
            n=ans;
        }
        
        if(n==1 or n==7)
        {
            return true;
        }
        return false;
    }
};