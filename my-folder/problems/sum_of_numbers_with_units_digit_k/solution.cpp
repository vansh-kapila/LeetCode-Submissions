class Solution {
public:
    int minimumNumbers(int num, int k) {
        int ans = 1e9;
        if(num==0)
        {
            return 0;
        }
        for(int i=1;i<=10000;i++)
        {
            if((k*i)%10==num%10 and num>=k*i)
            {
                ans = min(ans,i);
            }
        }
        if(ans==1e9)
        {
            return -1;
        }
        return ans;
    }
};