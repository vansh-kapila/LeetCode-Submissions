class Solution {
public:
    int countAsterisks(string s) {
        int c = 0;
        int count = 0;
        for(auto i:s)
        {
            if(i=='*' and c%2==0)
            {
                count++;
            }
            else if(i=='|')
            {
                c++;
            }
        }
        return count;
    }
};