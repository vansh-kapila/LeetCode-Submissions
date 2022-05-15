class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
         
        sort(special.begin(),special.end());
        special.insert(special.begin(),bottom-1);
        special.push_back(top+1);
        int ans = 0;
        for(int i=0;i<special.size()-1;i++)
        {
            ans = max(ans,special[i+1]-special[i]);
        }
        return ans-1;
    }
};