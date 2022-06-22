class Solution
{
    public:
        int getXORSum(vector<int> &arr1, vector<int> &arr2)
        {

            vector<int> v(31);
            vector<int> v2(31);
            for (int i = 0; i <= 30; i++)
            {
                int x = (int) pow(2, i);
                for (int j = 0; j < arr1.size(); j++)
                {
                    int y = (x &arr1[j]) ? 1 : 0;
                    v[i] = v[i] + y;
                }
                for (int j = 0; j < arr2.size(); j++)
                {
                    int y = (x &arr2[j]) ? 1 : 0;
                    v2[i] = v2[i] + y;
                }
            }

            int ans = 0;
            for (int i = 0; i <= 30; i++)
            {
                if (v[i] % 2 and v2[i] % 2)
                {
                    ans = ans + (int) pow(2, i);
                }
            }
            return ans;
        }
};