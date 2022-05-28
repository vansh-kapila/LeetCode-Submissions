class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string,int> m;
        for(int i=0;i<messages.size();i++)
        {    
            int count = 1;
               for(auto j:messages[i])
              {
                if(j==' ')
                {
                count++;
                }
              }
            m[senders[i]]+=count;
        }
        vector<pair<int,string>> v;
        for(auto i:m)
        {
            v.push_back({i.second,i.first});
        }
        sort(v.begin(),v.end(),greater<pair<int,string>>());
        int ans = v[0].first;
        string str;
        for(auto i:v)
        {
            if(i.first==ans)
            {
                str = max(str,i.second);
            }
        }
        return str;
    }
};