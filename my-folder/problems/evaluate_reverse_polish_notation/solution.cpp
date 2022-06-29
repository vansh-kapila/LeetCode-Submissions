class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        int ans = 0;
        for(auto i:tokens)
        {
            st.push(i);
            if(st.top()=="+" or st.top()=="-" or st.top()=="/" or st.top()=="*")
            {
                string op = st.top();
                st.pop();
                int x = stoi(st.top());
                st.pop();
                int y = stoi(st.top());
                st.pop();
                if(op=="+")
                {
                    ans=y+x;
                }
                if(op=="-")
                {
                    ans=y-x;
                }
                if(op=="/")
                {
                    ans=y/x;
                }
                if(op=="*")
                {
                    ans=y*x;
                }
                st.push(to_string(ans));
            }
        }
        return stoi(st.top());
    }
};