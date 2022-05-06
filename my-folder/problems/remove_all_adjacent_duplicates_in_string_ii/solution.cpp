class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>> st;
        for(int i=0;i<s.length();i++)
        {
            if(st.empty() or s[i]!=st.back().first)
            {
                st.push_back({s[i],1});
            }
            else
            {
                st.back().second++;
                if(st.back().second==k)
                {
                    st.pop_back();
                }
            }
        } 
        
        string str;
        for(auto i:st)
        {
            str.append(i.second,i.first);
        }
        return str;
    }
};