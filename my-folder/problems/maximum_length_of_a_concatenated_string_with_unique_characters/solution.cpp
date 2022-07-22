class Solution {
public:
    int ans = 0;
    void solve(vector<string> &arr,string &str,int n)
    {
        if(str.length()>26)
        {
            return;
        }
        set<char> st;
        for(auto i:str)
        {
            if(st.find(i)!=st.end())
            {
                return;
            }
            st.insert(i);
        }
        if(n==arr.size())
        {
            ans = max(ans,(int)str.length());
            return;
        }
        
        solve(arr,str,n+1);
        string y = str;
        str.append(arr[n]);
        solve(arr,str,n+1);
        str = y;
    }
    int maxLength(vector<string>& arr) {
        string str;
        int n = 0;
        solve(arr,str,n);
        return ans;
    }
};