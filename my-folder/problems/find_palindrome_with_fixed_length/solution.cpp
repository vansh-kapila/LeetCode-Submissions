class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        vector<long long> v;
        for(int i=0;i<queries.size();i++)
        {
            long long x = queries[i];
            long long n = (intLength+1)/2;
            long long y = (long long)pow(10,n-1)-1;
            if((int)log10(y+x)+1>n)
            {
                v.push_back(-1);
            }
            else
            {
                string str;
                long long m = x+y;
                while(m!=0)
                {
                    str.push_back(m%10+'0');
                    m=m/10;
                }
                string anss = str;
                reverse(str.begin(),str.end());
                if(intLength%2)
                {
                    str.erase(str.end()-1);
                }
                str.append(anss);  
                long long ans = 0;
                for(int i=0;i<str.length();i++)
                {
                    ans = ans*10+(str[i]-'0');
                }
                v.push_back(ans);
            }
        }
        return v;
    }
};