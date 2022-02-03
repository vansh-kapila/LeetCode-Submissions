class Solution {
public:
    vector<string> v;
    void solve(int n,int op,int cl,int i,string str){
        if(i==2*n and op==n and cl==n)
        {   
            v.push_back(str);
            return;
        }
        if(cl>op)
        {
            return;
        }
        if(cl>n or op>n)
        {
            return;
        }
        str.push_back('(');
        solve(n,op+1,cl,i+1,str);
        str[i]=(')');
        solve(n,op,cl+1,i+1,str);
    }
        
    vector<string> generateParenthesis(int n) {
       string str;
       solve(n,0,0,0,str);
       return v;
    }
};