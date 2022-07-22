class Solution {
public:
    string addStrings(string num1, string num2) {
        string str;
        int carry = 0;
        while(!num1.empty() and !num2.empty())
        {
            int x = num1.back()-'0'+num2.back()-'0'+carry;
            carry = x/10;
            x=x%10;
            str.push_back((x+'0'));
            num1.pop_back();
            num2.pop_back();
        }
        while(!num1.empty())
        {
            int x = num1.back()-'0'+carry;
            carry = x/10;
            x=x%10;
            str.push_back((x+'0'));
            num1.pop_back();
        }
        while(!num2.empty())
        {
            int x = num2.back()-'0'+carry;
            carry = x/10;
            x=x%10;
            str.push_back((x+'0'));
            num2.pop_back();
        }
        if(carry!=0)
        {
            str.push_back('0'+carry);
        }
        reverse(str.begin(),str.end());
        return str;
    }
};