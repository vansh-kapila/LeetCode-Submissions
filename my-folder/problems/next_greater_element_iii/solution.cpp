class Solution {
public:
    string nextperm(string str)
    {
        int ind = -1;
        for(int i=str.length()-2;i>=0;i--)
        {
            if(str[i]<str[i+1])
            {
                ind = i;
                break;
            }
        }
        if(ind==-1)
        {
            return "-1";
        }
        int ind2 = -1;
        for(int i=str.length()-1;i>=0;i--)
        {
            if(str[i]>str[ind])
            {
                ind2 = i;
                break;
            }
        }
        
        swap(str[ind],str[ind2]);
        reverse(str.begin()+ind+1,str.end());
        return str;
    }
    int nextGreaterElement(int n) {
        
        long long x = stol(nextperm(to_string(n)));
        
        if(x>INT_MAX)
        {
            return -1;
        }
        return x;
    }
};