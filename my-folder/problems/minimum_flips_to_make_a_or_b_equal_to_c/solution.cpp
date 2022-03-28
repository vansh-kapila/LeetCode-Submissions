class Solution {
public:
    int minFlips(int a, int b, int c) {
        vector<int> count(32);
        for(int i=0;i<32;i++)
        {
            int j = 1<<i;
            if((a&j))
            {
                count[i]++;
            }  
            if((b&j))
            {
                count[i]++;
            }  
        }
        int ans = 0;
        for(int i=0;i<32;i++)
        {  
            int j = 1<<i;
           if(!(c&j) and count[i]>0)
           {
               ans = ans+count[i];
           }
            if((c&j) and count[i]==0)
           {
               ans = ans+1;
           }
        }
        return ans;
    }
};