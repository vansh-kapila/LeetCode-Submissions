class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;
        int n = s.length();
        bool ans = true;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(' or s[i]=='{' or s[i]=='[')
            {
                ss.push(s[i]);
            }
            else
            {  if(ss.empty()==true)
               {
                ans = false;
                break;
               }
                else if(s[i]==')' and ss.top()=='(')
                {
                    ss.pop();
                }
                else if(s[i]==']' and ss.top()=='[')
                {
                    ss.pop();
                }
                else if(s[i]=='}' and ss.top()=='{')
                {
                    ss.pop();
                }
                else
                {
                    ans = false;
                    break;
                }
                                
            }
        }
        
        if(ans==false or ss.empty()==false)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};