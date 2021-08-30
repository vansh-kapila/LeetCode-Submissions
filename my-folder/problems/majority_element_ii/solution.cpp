class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
         unordered_map<int,int> m;
        vector<int> v;
        int n = arr.size();
        for(int i=0;i<n;i++)
        {
            m[arr[i]]++;
            
            if(m[arr[i]]>(n/3))
            {
                v.push_back(arr[i]);
                m[arr[i]]=-10000007;
            }
        }
        
        return v;
    }
};