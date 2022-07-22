class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string str;
        for(auto i:s)
        {
            if(i!='-')
            {
                str.push_back(toupper(i));
            }
        }
        int x = str.length()%k;
        if(x==0)
        {
            x+=k;
        }
        string ans;
        int y = k;
        k = x;
        for(auto i:str)
        {
            if(k==0)
            {
                k = y;
                ans.push_back('-');
            }
            k--;
            ans.push_back(i);
        }
        return ans;
    }
};