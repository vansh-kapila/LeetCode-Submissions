class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int l = 0;
        int r = people.size()-1;
        int ans = 0;
        while(l<=r)
        {
            if(people[l]+people[r]>limit or l==r)
            {
                r--;
                ans++;
            }
            else
            {
                l++;
                r--; 
                ans++;
            }
        }
        return ans;
    }
};