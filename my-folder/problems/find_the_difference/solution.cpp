class Solution {
public:
    char findTheDifference(string s, string t) {
         
        int ans = 0;
        for(int i=0;i<s.length();i++)
        {
           ans=ans^(s[i]-'a');  
        }
        for(int i=0;i<t.length();i++)
        {
           ans=ans^(t[i]-'a');  
        } 
        return 'a'+ans;
    }
};