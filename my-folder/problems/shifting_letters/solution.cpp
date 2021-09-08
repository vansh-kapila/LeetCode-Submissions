class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = shifts.size();
        vector<long> temp(n);
        temp[n-1]=shifts[n-1];
        for(int i=n-2;i>=0;i--)
        {
          temp[i]=shifts[i]+temp[i+1];
        }
        
        for(int i=0;i<shifts.size();i++)
        {
            s[i]='a'+((s[i]-'a')+temp[i])%26;
        }
        
        return s;
         
    }
};