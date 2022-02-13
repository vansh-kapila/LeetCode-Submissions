class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        map<int,int> m;
        for(int i=0;i<nums.size();i+=2)
        {
            m[nums[i]]++;
        } 
        
        map<int,int> m2;
        for(int i=1;i<nums.size();i+=2)
        {
            m2[nums[i]]++;
        } 
        
        int max1 = 0;
        int max2 = 0;
        int temp = 0;
        for(auto i:m)
        {
            if(i.second>temp)
            {
                max1 = i.first;
                temp = i.second;
            }
        }
        temp = 0;
        for(auto i:m2)
        {
            if(i.second>temp)
            {
                max2 = i.first;
                temp = i.second;
            }
        }
        int max3 = 0;
        int max4 = 0;
        temp = 0;
        for(auto i:m)
        {
            if(i.second>temp and i.first!=max1)
            {
                max3 = i.first;
                temp = i.second;
            }
        }
        temp = 0;
        for(auto i:m2)
        {
            if(i.second>temp and i.first!=max2)
            {
                max4 = i.first;
                temp = i.second;
            }
        }
        if(max1!=max2)
        {
            return nums.size()-m[max1]-m2[max2];
        }
        else
        {
            return min(nums.size()-m[max1]-m2[max4],nums.size()-m2[max2]-m[max3]);
        }
        
        
    }
};