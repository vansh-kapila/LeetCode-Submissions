class Solution {
public:
    int getLucky(string s, int k) {
        int ans = 0;
        for(auto i:s)
        {
            ans = ans + ((i-'a')+1)%10+((i-'a')+1)/10;
        } 
        k--;
        while(k--)
        {
            int x = 0;
            while(ans!=0)
            {
                x+=ans%10;
                ans/=10;
            }
            ans = x;
        }
        return ans;
    }
};