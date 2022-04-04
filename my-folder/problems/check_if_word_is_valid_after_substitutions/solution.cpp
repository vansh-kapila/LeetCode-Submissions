class Solution {
public:
    bool isValid(string s) {
        vector<int> ss;
        for(int i=0;i<s.length();i++)
        {
            int n = ss.size();
            if(s[i]=='c')
            {
                if(n>=2 and (ss[n-1]=='b' and ss[n-2]=='a'))
                {
                    ss.pop_back();
                    ss.pop_back();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                ss.push_back(s[i]);
            }
        }
        return ss.empty();
    }
};