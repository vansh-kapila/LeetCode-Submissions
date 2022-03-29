class Solution {
public:
    int tupleSameProduct(vector<int>& nums) { 
      int count = 0;
       unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                m[nums[j]*nums[i]]++;
            }
        }
      for(int i=0;i<nums.size();i++)
      {
          for(int j=i+1;j<nums.size();j++)
          {
               count+=(m[nums[i]*nums[j]]-1);
          }
      }
    return count*4;
    }
};