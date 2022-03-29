class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> m; 
        multiset<int> s;
        for(int i=0;i<arr.size();i++)
        {
            m[arr[i]]++;
        } 
        for(auto i:m)
        {
        s.insert(i.second); 
        }
        int count = 0;
        for(auto i:s)
        {    
            if(i<=k)
            {
               count++;
               k=k-i; 
            }
            else
            {
                break;
            }
        }
        return s.size()-count;
    }
};