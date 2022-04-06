class Solution {
public:
    bool reorderedPowerOf2(int n) {
        map<int,int> mp;
        string ptr = to_string(n);
        for(auto j:ptr)
        {
            mp[j]++;
        }
        for(int i=0;i<30;i++)
        {
            int x = 1<<i;
            map<char,int> m;
            string str = to_string(x);
            for(auto j:str)
            {
                m[j]++;
            }
            int count = 0;
            for(auto i:m)
            {
                if(i.second!=mp[i.first])
                {
                    count++;
                }
            }
            for(auto i:mp)
            {
                if(i.second!=m[i.first])
                {
                    count++;
                }
            }
            if(count==0)
            {   
                return true;
            }
        }
        return false;
    }
};