class Solution {
public: 
vector<int> ans;
void merge(pair<int, int> a[], int start,
                int mid, int end)
{
    pair<int, int> f[mid - start + 1],
                   s[end - mid];
                    
    int n = mid - start + 1;
    int m = end - mid;
     
    for(int i = start; i <= mid; i++)
        f[i - start] = a[i];
    for(int i = mid + 1; i <= end; i++)
        s[i - mid - 1] = a[i];
         
    int i = 0, j = 0, k = start;
    int cnt = 0;
  
    while(i < n && j < m)
    {
        if (f[i].second <= s[j].second)
        {
            ans[f[i].first] += cnt;
            a[k++] = f[i++];
        }
        else
        {
            cnt++;
            a[k++] = s[j++];
        }
    }
  
    while(i < n)
    {
        ans[f[i].first] += cnt;
        a[k++] = f[i++];
    }
  
    while(j < m)
    {
        a[k++] = s[j++];
    }
}
  
void mergesort(pair<int, int> item[],
                    int low, int high)
{
    if (low >= high)
        return;
         
    int mid = (low + high) / 2;
    mergesort(item, low, mid);
    mergesort(item, mid + 1, high);
    merge(item, low, mid, high);
} 


    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        map<int,int> m;
        for(int i=0;i<nums2.size();i++)
        {
            m[nums2[i]] = i;
        }
        for(int i = 0;i<nums1.size();i++)
        {
            nums1[i] = m[nums1[i]];
        } 
        ans.resize(n);
        pair<int,int> arr[n];
        for(int i=0;i<n;i++)
        {
         arr[i].second = nums1[i];
         arr[i].first = i;
        }
        mergesort(arr, 0, n-1); 
   
        long long anss =  0;
        for(int i =0; i < nums1.size() ; i++)
        {
        long long a  = n - i-1;
        long long b   = (a - ans[i]);
        long long c  = i;
        long long d    = nums1[i] - ans[i];
        
        anss += (b*d);
    }
        
    return anss;

    }
};