class Solution {
public:
    bool canChange(string start, string target) { 
        vector<pair<int,int>> startv;
        vector<pair<int,int>> targetv;
        for(int i=0;i<start.length();i++)
        {
            if(start[i]=='L')
            {
                startv.push_back({i,0});
            }
            else if(start[i]=='R')
            {
                startv.push_back({i,1});
            }
        }
        for(int i=0;i<target.length();i++)
        {
            if(target[i]=='L')
            {
                targetv.push_back({i,0});
            }
            else if(target[i]=='R')
            {
                targetv.push_back({i,1});
            }
        }
        if(targetv.size()!=startv.size())
        {
            return 0;
        }
        for(int i=0;i<startv.size();i++)
        {
            if(targetv[i].second!=startv[i].second)
            {
                return 0;
            }
            if(targetv[i].second==1 and targetv[i].first<startv[i].first)
            {
                return 0;
            }
            if(targetv[i].second==0 and targetv[i].first>startv[i].first)
            {
                return 0;
            }
        }
        return 1;
    }
};