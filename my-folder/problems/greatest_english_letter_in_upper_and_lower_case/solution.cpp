class Solution {
public:
    string greatestLetter(string s) {
        string ans;
        for(char c = 'Z';c>='A';c--)
        { 
            if(find(s.begin(),s.end(),c)!=s.end() and find(s.begin(),s.end(),(char)((int)c+32))!=s.end())
            {
                ans.push_back(c);
                break;
            }
        }
        return ans;
    }
};