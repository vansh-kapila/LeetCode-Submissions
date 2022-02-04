class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<pair<string,string>> v;
        for(int i=0;i<strs.size();i++)
        {
            string x = strs[i];
            sort(x.begin(),x.end());
            v.push_back(make_pair(x,strs[i]));
        }
        
        sort(v.begin(),v.end());
        
        vector<vector<string>> ans;
        vector<string> temp;
        int i = 0;
        while(i<strs.size())
        {   
            temp.clear();
            string x = v[i].first;
            while(i<strs.size() and v[i].first==x)
            {         
                temp.push_back(v[i].second);
                i++;
            } 
            ans.push_back(temp);
        }
        return ans;
    }
};