class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        multiset<int> s(arr.begin(),arr.end());
        sort(arr.begin(),arr.end());
        if(s.count(0)%2==1)
        {
            return 0;
        }
        else
        {
            s.erase(0);
        }
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]!=0 and s.find(2*arr[i])!=s.end() and s.find(arr[i])!=s.end())
            {
                s.erase(s.find(arr[i]));
                s.erase(s.find(2*arr[i]));
            } 
        }
        return s.empty();
    }
};