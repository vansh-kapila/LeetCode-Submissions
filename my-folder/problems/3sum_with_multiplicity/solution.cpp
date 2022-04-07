class Solution
{
    public:
        int threeSumMulti(vector<int> &arr, int target)
        {
            unordered_map<int, long long > m; 
            set<int> s;
            for (int i = 0; i < arr.size(); i++)
            {
                m[arr[i]]++;
                s.insert(arr[i]);
            }
            arr.clear();
            for(auto i:s)
            {
                arr.push_back(i);
            } 
            int mod = 1000000007; 
            long long ans = 0; 
            for (int i=0;i<arr.size();i++)
            {
                int l = i;
                int r = arr.size() - 1;
                while (l<arr.size() and r>=0 and l<=r)
                {
                    if (arr[l] + arr[r] + arr[i] == target)
                    {   
                        
                        //cout<<arr[i]<<' '<<arr[l]<<' '<<arr[r]<<endl;
                        if (arr[l] == arr[r] and arr[r] == arr[i])
                        {
                            ans = (ans + (m[arr[l]] *(m[arr[l]] - 1) *(m[arr[l]] - 2) / 6) % mod);
                        }
                        else if (arr[l] == arr[r])
                        {
                            ans = (ans + m[arr[l]] *(m[arr[l]] - 1) / 2 *m[arr[i]]) % mod;
                        }
                        else if (arr[l] == arr[i])
                        {
                            ans = (ans + m[arr[l]] *(m[arr[l]] - 1) / 2 *m[arr[r]]) % mod;
                        }
                        else if (arr[i] == arr[r])
                        {
                            ans = (ans + m[arr[i]] *(m[arr[i]] - 1) / 2 *m[arr[l]]) % mod;
                        }
                        else
                        {
                            ans = (ans + m[arr[l]] *m[arr[r]] *m[arr[i]]) % mod;
                        }
                        l++;
                        r--;
                    }
                    else if (arr[l] + arr[r] + arr[i] > target)
                    {   
                        r--;
                    }
                    else
                    {
                        l++;
                    }
                }
            }

            return (ans % 1000000007);
        }
};