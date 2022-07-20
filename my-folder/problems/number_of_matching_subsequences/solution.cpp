class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> arr(26);
        int j = 0;
        for(auto i:s)
        {
            arr[i-'a'].push_back(j++);
        }
        
        int count = 0;
        for(auto i:words)
        {
            int k = -1;
            for(int j=0;j<i.length();j++)
            {
                char c = i[j];
                auto it = upper_bound(arr[c-'a'].begin(),arr[c-'a'].end(),k);
                if(it==arr[c-'a'].end())
                {
                    k=-1;
                    break;
                }
                k = *it;
            }
            count+=k!=-1;
        }
        return count;
    }
};