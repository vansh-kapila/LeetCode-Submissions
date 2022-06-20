class Solution {
public:
    vector<vector<string>> ans;
    bool ispal(string &x)
    {
        string y = x;
        reverse(y.begin(),y.end());
        return (y==x);
    }
    void solve(string &s,int index,int lasttaken,vector<string> v)
    {
        if(index==s.length())
        {
            string x = s.substr(lasttaken,s.length()-lasttaken);
            if(!x.empty() and ispal(x))
            {
                v.push_back(x);
                ans.push_back(v);
            }
            return;
        }
        solve(s,index+1,lasttaken,v);
        string y = s.substr(lasttaken,index-lasttaken);
        if(ispal(y))
        {
            if(!y.empty()){
            v.push_back(y);
            solve(s,index+1,index,v); }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> v;
        solve(s,0,0,v);
        return ans;
    }
};