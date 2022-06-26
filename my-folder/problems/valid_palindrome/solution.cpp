class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for(auto i:s)
        {
            if(i>='A' and i<='Z')
            {
                str.push_back((char)(i+32));
            }
            else if((i>='a' and i<='z') or (i>='0' and i<='9'))
            {
                str.push_back(i);
            }
        }
        string ptr = str;
        reverse(str.begin(),str.end());
        return str==ptr;
    }
};