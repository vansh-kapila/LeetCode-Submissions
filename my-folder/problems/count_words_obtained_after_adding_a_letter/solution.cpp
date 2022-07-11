class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        set<vector<int>> st;
        int count = 0;
        for(auto i:startWords)
        {
            vector<int> v(26,0);
            for(auto j:i)
            {
                v[j-'a']++;
            }
            st.insert(v);
        }
        for(auto i:targetWords)
        {
            vector<int> v(26,0);
            for(auto j:i)
            {
                v[j-'a']++;
            } 
            for(auto j:i)
            {
                v[j-'a']--;
                if(st.find(v)!=st.end())
                { 
                    count++;
                    break;
                }
                v[j-'a']++;
            }
        }
        return count;
    }
};