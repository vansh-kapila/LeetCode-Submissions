class Solution {
public: 
    bool valid(string &str)
    {
        if(str[0]>'2')
        {
            return 0;
        }
        if(str[0]=='2' and str[1]>='4')
        {
            return 0;
        }
        if(str[3]>='6')
        {
            return 0;
        }
        return 1;
    }
    string time(vector<int> &arr)
    {
        string ret;
        ret.push_back(arr[0]+'0');
        ret.push_back(arr[1]+'0');
        ret.push_back(':');
        ret.push_back(arr[2]+'0');
        ret.push_back(arr[3]+'0');
        return ret;
    }
    string largestTimeFromDigits(vector<int>& arr) { 
        sort(arr.begin(),arr.end());
        string ans;
        string str = time(arr);
        if(valid(str))
        {
            ans = max(ans,str);
        }
        while(next_permutation(arr.begin(),arr.end()))
        {
            string str = time(arr);
            if(valid(str))
            {
                ans = max(ans,str);
            }
        }
        return ans;
    }
};