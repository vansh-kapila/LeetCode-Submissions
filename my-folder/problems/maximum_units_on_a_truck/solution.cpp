class Solution {
public:
    static bool comp(vector<int> &x,vector<int> &y)
    {
        return x[1]>y[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),comp);
        int ans = 0;
        for(int i=0;i<boxTypes.size();i++)
        {
            ans = ans+min(truckSize,boxTypes[i][0])*boxTypes[i][1];
            truckSize -= min(truckSize,boxTypes[i][0]);
        }
        return ans;
    }
};