class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        for(int i=0;i<n;i++)
        {
            s = s[n-1]+s;
            s.erase(n);
            if(s==goal)
            {
                return true;
            }
        }
        return false;
    }
};