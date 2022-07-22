class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> s;
        for(auto i:emails)
        {
            string str;
            bool atenc = 0;
            bool skip = 0;
            for(auto j:i)
            {
                if(j=='@')
                {
                    skip = 0;
                    atenc = 1;
                }
                if(atenc)
                {
                    str.push_back(j);
                }
                else if(skip)
                {
                    continue;
                }
                else if(j=='.' and atenc == 0)
                {
                    continue;
                }
                else if(j=='+' and atenc == 0)
                { 
                    skip = 1;
                }
                else
                {
                    str.push_back(j);
                }
            } 
            s.insert(str);
        }
        return s.size();
    }
};