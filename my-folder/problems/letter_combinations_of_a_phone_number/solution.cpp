class Solution {
public:
    vector<string> v = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    void solve(string &digits,string &str,int i)
    {
        if(i==str.length())
        {   
            ans.push_back(str);
            return;
        }
        char c = digits[i];
        for(int j=0;j<v[c-'0'].size();j++)
        {   
            str[i]=v[c-'0'][j];
            solve(digits,str,i+1);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
        {
            return {};
        }
        string str = digits;
        solve(digits,str,0);
        return ans;
    }
};