class Solution {
public:
    string digitSum(string s, int k) {
        
        string ans=s;
        while(ans.length()>k)
        {
            string ptr;
            int x = 0;
            int y = 0;
            for(int i=0;i<ans.length();i++)
            {
                x = x+(ans[i]-'0');
                y++;
                if(y==k)
                {
                    y = 0;             
                    ptr.append(to_string(x));
                    x=0;
                }
            }
            if(y!=0)
            {
                y = 0;             
                ptr.append(to_string(x));
                x=0;
            }
            ans = ptr;
        }
        return ans;
    }
};