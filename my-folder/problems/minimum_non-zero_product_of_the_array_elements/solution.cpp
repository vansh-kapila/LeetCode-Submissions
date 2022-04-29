class Solution
{
    public:
        long long MOD = 1e9 + 7;
    long long fastpow(long long N, long long K)
    {
        if (K == 0) return 1;
        if (K == 1) return N % MOD;
        if (K % 2 == 0)
        {
            long long temp = fastpow(N, K / 2);
            return (temp *temp) % MOD;
        }
        else
        {
            long long temp = fastpow(N, K / 2);
            temp = (temp *temp) % MOD;
            return (temp *(N % MOD)) % MOD;
        }
    }

    int minNonZeroProduct(int p)
    {
        long long mod = 1e9 + 7;
        long long y = ((long long) pow(2, p) - 1) % mod;
        long long ans = (fastpow((long long) pow(2, p) - 2, (long long) pow(2, p - 1) - 1) *y) % mod;
        return ans;
    }
};