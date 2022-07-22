class Solution {
public:
    string reverseVowels(string s) {
        string vowels;
        string fnd = "aeiouAEIOU";
        for(auto i:s)
        {
            if(find(fnd.begin(),fnd.end(),i)!=fnd.end())
            {
                vowels.push_back(i);
            }
        } 
        string ans;
        for(auto i:s)
        {
            if(find(fnd.begin(),fnd.end(),i)!=fnd.end())
            {
                ans.push_back(vowels.back());
                vowels.pop_back();
                continue;
            }
            ans.push_back(i);
        }
        return ans;
    }
};