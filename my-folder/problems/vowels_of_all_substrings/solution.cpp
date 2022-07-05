class Solution {
public:
    long long countVowels(string word) {
        long long ans = 0;
        for(int i=0;i<word.length();i++)
        {
            if(word[i]=='a' or word[i]=='e' or word[i]=='i' or word[i]=='o' or word[i]=='u')
            {
                ans = ans + (long long)(i+1)*(word.length()-i);
            }
        }
        return ans;
    }
};