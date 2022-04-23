class Solution {
public: 
    int maxProduct(vector<string>& words) {
        for(int i=0;i<words.size();i++)
        {
            sort(words[i].begin(),words[i].end());
        }
        sort(words.begin(),words.end());
        int ans = 0;
        for(int i=0;i<words.size();i++)
        {
            for(int j=i+1;j<words.size();j++)
            {   bool chk = 1;
                for(int k=0;k<26;k++)
                {
                    if(binary_search(words[i].begin(),words[i].end(),k+'a') and binary_search(words[j].begin(),words[j].end(),k+'a'))
                    {   
                        chk = 0;
                        break;
                    }
                }
                if(chk==1){
                int y = words[i].length()*words[j].length();
                ans = max(ans,y);}
            }
        }
        return ans;
    }
};