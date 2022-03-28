class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b = 0;
        int a = 0;
        int l = 0;
        int o = 0;
        int n = 0; 
        for(int i=0;i<text.length();i++)
        {
            if(text[i]=='b')
            {
                b++;
            }
             if(text[i]=='a')
            {
                a++;
            }
             if(text[i]=='l')
            {
                l++;
            }
             if(text[i]=='n')
            {
                n++;
            } 
             if(text[i]=='o')
            {
                o++;
            }
        }
        return min({b,a,o/2,l/2,n});
    }
};