class Solution {
public:
    bool isPalindrome(int x) {
        long long a=0;
        long long temp = x;
        while(x!=0)
        {
            a=a*10+x%10;
            x=x/10;
        }
        
        if(a==temp and temp>=0)
            return true;
        else
            return false;
    }
};