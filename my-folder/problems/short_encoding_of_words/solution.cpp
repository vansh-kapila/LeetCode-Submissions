class Solution {
public:
    int wordcontains(vector<string> &words,int j,int i)
    {
        for(int k=0;k<min(words[i].length(),words[j].length());k++)
        {
            if(words[i][k]!=words[j][k])
            {
                return 0;
            }
        }
        return 1;
    }
    int minimumLengthEncoding(vector<string>& words) {
        for(auto &i:words)
        {
            reverse(i.begin(),i.end());
        }
        sort(words.begin(),words.end());
        int sequence=0; 
        for(int i=0;i<words.size();i++)
        {
            while(i+1<words.size() and wordcontains(words,i+1,i))
            {
                i++;
            }
            sequence=sequence+(words[i].length()+1);
        }
        return sequence;
    }
};