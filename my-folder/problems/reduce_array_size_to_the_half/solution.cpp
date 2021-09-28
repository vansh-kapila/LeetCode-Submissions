class Solution {
public:
    int minSetSize(vector<int>& arr) {
         unordered_map<int,int> m;
        
        
        for(int i=0;i<arr.size();i++)
        {
            m[arr[i]]++;
        }
        vector<int> v;
        for(auto i:m)
        {
            v.push_back(i.second);
        }
        
        
        sort(v.begin(),v.end(),greater<int>());
        int count = 0;
        int ans = 0;
        for(int i=0;i<v.size();i++)
        {
            count+=v[i];
            ans++;
            if(count>=arr.size()/2)
            {
                return ans;
            }
        }
        
        return -1;
    }
};