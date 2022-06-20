class Solution {
public:
    int longestSubsequence(string s, int k) {
        
        long long ans = 0;
        int x = 0;
        int j = 0;
        long long m = s.length()-1;
        int z = 0;
        for(int i=0;i<s.length();i++)
        {
            z =  z+(s[i]=='0');
        }
        long long ss = 60;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i]=='1')
            {
                ans = ans+(long long)pow(2,min(ss,m-i));
                long long y = (long long)pow(2,60);
                ans = min(ans,y);
            }
            else
            { 
                z--;
            }
            while(ans>k)
            {
                ans/=2;
                m--;
            }  
            int k = m-i+z+1;  
            x = max(x,k);
        } 
        return x;
    }
};