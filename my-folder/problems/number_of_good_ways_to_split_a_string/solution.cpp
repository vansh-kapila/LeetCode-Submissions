class Solution {
public:
    int numSplits(string s) {
        vector<vector<int>> pref(s.length(),vector<int>(26,0));
        vector<vector<int>> suff(s.length(),vector<int>(26,0));
        
        for(int i=0;i<s.length();i++)
        { 
            if(i==0)
            {
                pref[i][s[i]-'a']++;
            }
            else
            {
                pref[i]=pref[i-1];
                pref[i][s[i]-'a']++;
            }
        }
        
        
        for(int i=s.length()-1;i>=0;i--)
        {
            if(i==s.length()-1)
            {
                suff[i][s[i]-'a']++;
            }
            else
            {
                suff[i]=suff[i+1];
                suff[i][s[i]-'a']++;
            }
        } 
        int count = 0;
        for(int i=1;i<s.length();i++)
        {
            int distpref=0,distsuff=0;
            for(auto &j:pref[i-1])
            {  
                if(j>0)
                { 
                    distpref++;
                }
            }
            for(auto &j:suff[i])
            {
                if(j>0)
                { 
                    distsuff++;
                }
            }
            if(distpref==distsuff)
            { 
                count++;
            }
        }
        return count;
    }
};