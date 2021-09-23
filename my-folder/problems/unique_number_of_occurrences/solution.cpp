class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;
        
        for(int i=0;i<arr.size();i++)
        {
            m[arr[i]]++;
        }
        unordered_map<int,int> m2;
        for(auto i:m)
        {
           m2[i.second]++;
        }
        
        for(auto i:m2)
        {
            if(i.second!=1)
            {
                return false;
            }
        }
        return true;
    }
};