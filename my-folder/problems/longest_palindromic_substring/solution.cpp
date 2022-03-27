class Solution {
public:
    string longestPalindrome(string s) {
        int l = 0;
        int n = s.length();
        string ans;
        for(int i=0;i<s.length();i++)
        {
            string temp;
            temp.push_back(s[i]);
            int l = i-1;
            int r = i+1;
            while(l>=0 and r<n)
            {
                if(s[l]==s[r])
                {
                    temp.push_back(s[l]);
                    l--;
                    r++;
                }
                else
                {
                    break;
                }
            }
            if(temp.length()>ans.length())
            {
                ans = temp;
            }
        }
        if(!ans.empty()){
        string x = ans;
        reverse(x.begin(),x.end());
        ans.erase(ans.begin());
        x.append(ans);
        ans = x;}
        for(int i=0;i<s.length();i++)
        {
            string temp;
            if(s[i]==s[i+1] and i+1<s.length()){
            temp.push_back(s[i]); 
            int l = i-1;
            int r = i+2;
            while(l>=0 and r<n)
            {
                if(s[l]==s[r])
                {
                    temp.push_back(s[l]);
                    l--;
                    r++;
                }
                else
                {
                    break;
                }
            }
            if(temp.length()>=(ans.length()+1)/2)
            {
                string x = temp;
                reverse(temp.begin(),temp.end());
                temp=temp+x;
                ans = temp;
            }
            }
        }
        return ans;
    }
};