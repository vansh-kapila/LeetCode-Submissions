class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int ans = 0;
        string str = to_string(num);
        for(int i=0;i<str.length();i++)
        {
            for(int j=i;j<str.length();j++)
            {
                string kk; 
                if(j-i==k-1){
                for(int x=i;x<=j;x++)
                {
                    kk.push_back(str[x]);
                }
                int x = stoi(kk);
                if(x!=0 and num%x==0)
                {
                    ans++;
                }
                    }
            }
        }
        return ans;
    }
};