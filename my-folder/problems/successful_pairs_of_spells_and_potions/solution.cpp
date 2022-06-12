class Solution {
public:
    
    int count(vector<int> &v, long long k){
    int n = v.size();
    int l = 0;
    int r = n - 1;
    int leftGreater = n;
 

    while (l <= r) {
        int m = l + (r - l) / 2;
 
        if (v[m] > k){
            leftGreater = m;
            r = m - 1;
        }
 
        else
            l = m + 1;
        }

        return (n - leftGreater);
    
    }
    
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans(spells.size(), 0);
        for(int i=0;i<spells.size();i++){
            int temp;
            if(success%spells[i] == 0) {
                long long ch = (success/spells[i]);
                temp = count(potions, ch - 1);
            }
            else{
                long long ch = (success/spells[i]);
                temp = count(potions, ch);
            }
            ans[i] = (temp);
        }
        return ans;
        
        
    }
};