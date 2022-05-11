class Solution {
public:
    int integerBreak(int n) {
        int ans = 0;
        for(int i=2;i<=n;i++)
        {   
            int x = n/i;
            int y = n%i;
            ans = max((int)pow(x,i-y)*(int)pow((x+1),y),ans);
        }
        return ans;
    }
};