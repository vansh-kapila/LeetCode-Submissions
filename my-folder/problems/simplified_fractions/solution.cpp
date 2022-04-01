class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {   
                string ptr;
                ptr.append(to_string(j));
                ptr.push_back('/');
                ptr.append(to_string(i));
                if(!(__gcd(i,j)-1))
                {
                   ans.push_back(ptr);
                }
            }
        }
        return ans;
    }
};