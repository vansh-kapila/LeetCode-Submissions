class Solution {
public:
    set<string> st;
    vector<string> v;
    void solve(string &s,int n,string &ans)
    { 
        if(n==s.length())
        {
            v.push_back(ans);
            return;
        }
        string str;
        for(int i=n;i<s.length();i++)
        {
            str.push_back(s[i]);
            //cout<<str<<endl;
            if(st.find(str)!=st.end())
            {
                string x = " ";
                string y = ans;
                if(!ans.empty())
                {
                    ans.append(x);
                }
                ans.append(str);
                solve(s,i+1,ans);
                ans = y;
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto i:wordDict)
        {
            st.insert(i);
        }
        string ans;
        solve(s,0,ans);
        return v;
    }
};