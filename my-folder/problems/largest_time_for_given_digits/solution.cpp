class Solution
{
    public:
        bool validstring(string & str)
        {
            if (str[0] >= '3')
            {
                return 0;
            }
            if (str[0] == '2' and str[1] >= '4')
            {
                return 0;
            }
            if (str[3] >= '6')
            {
                return 0;
            } 
            return 1;
        }
    
    string largestTimeFromDigits(vector<int> &arr)
    {
        string ans;
        sort(arr.begin(),arr.end());
        ans.push_back('0' + arr[0]);
        ans.push_back('0' + arr[1]);
        ans.push_back(':');
        ans.push_back('0' + arr[2]);
        ans.push_back('0' + arr[3]);
        if (!validstring(ans))
        {
            ans.clear();
        } 
        string str;
        while (next_permutation(arr.begin(), arr.end()))
        {
            str.push_back('0' + arr[0]);
            str.push_back('0' + arr[1]);
            str.push_back(':');
            str.push_back('0' + arr[2]);
            str.push_back('0' + arr[3]);
            if (!validstring(str))
            {
                str.clear();
            }
            ans = max(ans, str);
            str.clear();
        }
        return ans;
    }
};