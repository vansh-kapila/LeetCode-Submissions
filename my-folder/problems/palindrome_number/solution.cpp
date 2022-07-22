class Solution {
public:
    bool isPalindrome(int x) {
        string xx = to_string(x);
        
        string y = xx;
        reverse(xx.begin(),xx.end());
        return xx==y;
    }
};