class Solution {
public:
    string minimizeResult(string expression) {
        string x,y;
        int index = 0;
        for(int i=0;i<expression.length();i++)
        {   
            if(expression[i]=='+')
            {   
                index = i;
                break;
            }
            x.push_back(expression[i]);
        }
        for(int i=index+1;i<expression.length();i++)
        {   
            y.push_back(expression[i]);
        } 
        int ans = INT_MAX;
        vector<pair<int,vector<string>>> v;
        for(int i=0;i<x.length();i++)
        {
            for(int j=0;j<y.length();j++)
            {
                string s = x.substr(0,i);
                string p = x.substr(i,x.length()-i);
                string ss = y.substr(0,j+1);
                string pp = y.substr(j+1,y.length()-j-1);
                int s1 = 1,p1 = 1,ss1 = 1,pp1 = 1; 
                if(!s.empty())
                {
                  s1 = stoi(s);
                }
                if(!p.empty()){
                p1 = stoi(p);}
                if(!ss.empty()){
                ss1 = stoi(ss);}
                if(!pp.empty()){
                pp1 = stoi(pp);}  
                //cout<<s1<<' '<<p1<<' '<<ss1<<' '<<pp1<<endl;
                vector<string> kp = {s,p,ss,pp};
                v.push_back({s1*(p1+ss1)*pp1,kp});
            }
        }
        sort(v.begin(),v.end());
        vector<string> temp = v[0].second;
        string ret;
        ret.append(temp[0]);
        ret.push_back('(');
        ret.append(temp[1]);
        ret.push_back('+');
        ret.append(temp[2]);
        ret.push_back(')');
        ret.append(temp[3]);
        return ret;
    }
};