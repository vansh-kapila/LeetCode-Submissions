class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        map<int,int> lose;
        set<int> s;
        for(int i=0;i<matches.size();i++)
        {
           lose[matches[i][1]]++; 
           s.insert(matches[i][0]);
            if(s.find(matches[i][1])!=s.end())
            {
                s.erase(s.find(matches[i][1]));
            }
        }
        vector<int> v,v2;
        vector<vector<int>> ans;
        for(auto i:s)
        {   if(lose.find(i)==lose.end()){
            v.push_back(i);}
        }
        ans.push_back(v);
         for(auto i:lose)
        {
            if(i.second==1)
            {
                v2.push_back(i.first);
            }
        }
        ans.push_back(v2);
        return ans;
    }
};