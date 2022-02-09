class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        multiset<int> s;
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        } 
        for(auto i:s)
        {
            for(int j=1;j<=k-1;j++)
            {
               if(s.find(i+j)==s.end())
               {
                   return false;
               }
               else
               {
                    auto it = s.find(i+j);
                    s.erase(it);
               }
            }
        }
        
        return true;
    }
};