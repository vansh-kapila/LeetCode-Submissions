class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        if(password.length()<8)
        {
            return 0;
        }
        bool ans = 0;
        for(char c = 'A';c<='Z';c++)
        {
            if(find(password.begin(),password.end(),c)!=password.end())
            {
                ans = 1;
            }
        }
        if(!ans)
        {
            return 0;
        }
        ans = 0;
        for(char c = 'a';c<='z';c++)
        {
            if(find(password.begin(),password.end(),c)!=password.end())
            {
                ans = 1;
            }
        }
        if(!ans)
        {
            return 0;
        }
        ans = 0;
        for(char c = '0';c<='9';c++)
        {
            if(find(password.begin(),password.end(),c)!=password.end())
            {
                ans = 1;
            }
        }
        if(!ans)
        {
            return 0;
        }
        ans = 0;
        string str = "!@#$%^&*()-+";
        int i = 0;
        for(i=0;i<str.length();i++)
        {
            char c = str[i];
            if(find(password.begin(),password.end(),c)!=password.end())
            {
                ans = 1;
            }
        }
        if(!ans)
        {
            return 0;
        }
        
        for(int i=0;i<password.length()-1;i++)
        {
            if(password[i]==password[i+1])
            {
                return 0;
            }
        }
        return 1;
    }
};