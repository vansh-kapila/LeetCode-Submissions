class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int length = __gcd(str1.length(),str2.length());
        string str = str1.substr(0,length);
        for(int i=0;i<str1.length();i++)
        {
            if(str[i%str.length()]!=str1[i])
            {
                return "";
            }
        }
        for(int i=0;i<str2.length();i++)
        {
            if(str[i%str.length()]!=str2[i])
            {
                return "";
            }
        }
        return str;
    }
};