class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        int kk = k;
        if(num.length()==k)
        {
            return "0";
        }
        for(auto c:num)
        {   
            if(ans.empty())
            {
                ans.push_back(c);
                continue;
            }
            while(!ans.empty() and c<ans.back() and k>0)
            {
                ans.pop_back(); 
                k--;
            }
            ans.push_back(c);
        }
        
        int index = -1;
        ans = ans.substr(0,num.length()-kk); 
        for(int i=0;i<ans.length();i++)
        {
            if(ans[i]=='0')
            {
                index = i;
            }
            else
            {
               break; 
            }
        }
        ans.erase(ans.begin(),ans.begin()+index+1);
        if(ans.empty())
        {
            return "0";
        } 
        return ans;
    }
};