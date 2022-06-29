class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0;
        map<char,int> v;
        bool oddpres = 0;
        for(auto i:s)
        {
            v[i]++;
        }
        
        for(auto i:v)
        {
            ans = ans+i.second/2;
            oddpres = (i.second%2)|oddpres;
        }
        
        if(oddpres)
        {
            return 2*ans+1;
        }
        return 2*ans;
    }
};