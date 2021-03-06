class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto i:s)
        {
            if(i=='(' or i=='{' or i=='[')
            {
                st.push(i);
            }
            else if(!st.empty() and i==')' and st.top()!='(')
            {
                return 0;
            }
            else if(!st.empty() and i==')' and st.top()=='(')
            {
                st.pop();
            }
            else if(!st.empty() and i=='}' and st.top()!='{')
            {
                return 0;
            }
            else if(!st.empty() and i=='}' and st.top()=='{')
            {
                st.pop();
            }
            else if(!st.empty() and i==']' and st.top()!='[')
            {
                return 0;
            }
            else if(!st.empty() and i==']' and st.top()=='[')
            {
                st.pop();
            }
            else
            {
                st.push(i);
            }
        }
        return st.empty();
    }
};