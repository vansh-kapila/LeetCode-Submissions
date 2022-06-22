class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
         long long maxx = k;
         long long ans = maxx*(maxx+1)/2;
         set<int> st(nums.begin(),nums.end()); 
         for(auto i:st)
         {
             if(i<=(int)maxx)
             {
                 maxx++;
                 ans = ans+maxx-i;
             }
             else
             {
                 break;
             }
         }
         return ans;
    }
};