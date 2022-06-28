class Solution {
public:
    string removeDigit(string number, char digit) {
         
        string maxima;
        for(int i=0;i<number.length();i++)
        {
            if(number[i]==digit)
            {
                string str = number;
                str.erase(str.begin()+i);
                maxima = max(maxima,str);
            }
        }
        return maxima;
    }
};