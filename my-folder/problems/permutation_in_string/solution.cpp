class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())
        {
            return false;
        }
        vector<int> v(26,0);
        vector<int> count(26,0);
        
        for(int i=0;i<s1.size();i++)
        {
            count[s1[i]-'a']++;
            v[s2[i]-'a']++;
        }
        
        if(v==count)
        {
            return true;
        }
        
        for(int i=s1.size();i<s2.size();i++)
        {
            v[s2[i]-'a']++; 
            v[s2[i-s1.size()]-'a']--;
            if(v==count)
            {
                return true;
            }
        }
        return false;
        
    }
};