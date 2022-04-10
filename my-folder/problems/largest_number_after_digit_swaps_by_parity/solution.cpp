class Solution {
public:
    int largestInteger(int num) {
        string str = to_string(num);
        vector<int> o;
        vector<int> e;
        for(int i=0;i<str.length();i++)
        {
            if((str[i]-'0')%2)
            {
                o.push_back(str[i]-'0');
            }
            else
            {
                e.push_back(str[i]-'0');
            }
        }
        sort(o.begin(),o.end(),greater<int>());
        sort(e.begin(),e.end(),greater<int>());
        string ptr;
        int j = 0;
        int k = 0;
        for(int i=0;i<str.length();i++)
        {
            if((str[i]-'0')%2)
            {
                ptr.push_back(o[j++]+'0');
            }
            else
            {
                ptr.push_back(e[k++]+'0');
            }
        } 
        int ans = stoi(ptr);
        return ans;
    }
};