class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        for(int i=0;i<strs.size();i++)
        {
            if(i==0)
            {
                ans = strs[i];
            }
            else
            {
                int j = 0;
                int k = 0;
                while(j<strs[i].length() and k<ans.length() and strs[i][j]==ans[k])
                {
                    j++;
                    k++;
                }
                while(ans.size()>=j+1)
                {
                    ans.pop_back();
                }
            }
        }
        return ans;
    }
};