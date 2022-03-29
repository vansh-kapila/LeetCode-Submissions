class Solution {
public:
    int numSplits(string s) {
        unordered_map<char,int> s1;
        unordered_map<char,int> s2;
        int count = 0;
        for(int i=0;i<s.length();i++)
        {
            s2[s[i]]++;
        }
        for(int i=0;i<s.length();i++)
        {
            if(s1.size()==s2.size())
            {
                count++;
            } 
            s2[s[i]]--;
            if(s2[s[i]]==0)
            {
                s2.erase(s2.find(s[i]));
            }
            s1[s[i]]++;
        }
        return count;
    }
};