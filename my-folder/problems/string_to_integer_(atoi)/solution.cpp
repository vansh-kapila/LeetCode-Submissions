class Solution {
public:
    int myAtoi(string &str) {
    long long ans = 0;
    long long x = 1;
    for(int i = 0; i<str.length();)
    {
        i = str.find_first_not_of(' ');
        if(i>=str.length())
        {
            break;
        }
        if(str[i] == '-' or str[i] == '+')
        {
            x = (str[i++] == '-') ? -1 : 1;
        }
        while(str[i]>='0' && str[i] <= '9') 
        {
            ans = ans*10 + (str[i++]-'0');
            if(x*ans >= INT_MAX) return INT_MAX;
            if(x*ans <= INT_MIN) return INT_MIN;                
        }
        return x*ans;
    }
    return x*ans;
    }
};