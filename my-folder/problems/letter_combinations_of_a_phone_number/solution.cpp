class Solution {
public:
    vector<string> store = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    void solve(string &digits,string &str,int i)
    {
        if(i==digits.length())
        {
            ans.push_back(str);
            return;
        }
        for(auto j:store[digits[i]-'0'])
        {
            str.push_back(j);
            solve(digits,str,i+1); 
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
         if(digits.empty())
        {
            return {};
        }
        string str;
        solve(digits,str,0);
        return ans;
    }
};