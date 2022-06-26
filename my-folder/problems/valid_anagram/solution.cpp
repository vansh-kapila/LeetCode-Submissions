class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> ms;
        map<char,int> mt;
        
        for(auto i:s)
        {
            ms[i]++;
        }
        for(auto i:t)
        {
            mt[i]++;
        }
        return ms==mt;
    }
};