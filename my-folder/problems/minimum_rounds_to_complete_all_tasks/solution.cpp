class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        vector<int> freq;
        map<int,int> m;
        for(auto i:tasks)
        {
            m[i]++;
        }
        for(auto i:m)
        {
            freq.push_back(i.second);
        }
        sort(freq.begin(),freq.end());
        if(freq[0]==1)
        {
            return -1;
        }
        int ans = 0;
        for(int i=0;i<freq.size();i++)
        {
            ans = ans+(freq[i]+2)/3;
        }
        return ans;
    }
};