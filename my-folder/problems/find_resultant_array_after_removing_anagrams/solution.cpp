class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) { 
        for(int i=words.size()-2;i>=0;i--)
        {       
                int j = i+1;
                if(words[i]!="0" and words[j]!="0"){
                vector<int> v(26);
                vector<int> w(26);
                for(int k=0;k<26;k++)
                {
                    v[k]=0;
                    w[k]=0;
                }
                for(int k=0;k<words[i].length();k++)
                {   
                    v[words[i][k]-'a']++;
                }
                for(int k=0;k<words[j].length();k++)
                {
                    w[words[j][k]-'a']++;
                }
                if(v==w)
                {
                    words[j] = "0";
                }
                } 
        }
        vector<string> ans;
        for(int i=0;i<words.size();i++)
        {
            if(words[i]!="0")
            {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};