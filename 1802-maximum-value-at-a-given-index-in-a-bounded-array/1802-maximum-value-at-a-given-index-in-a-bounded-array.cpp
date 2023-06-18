class Solution {
public:
    long apSum(int a , int d , int n)
    {
        if(n == 1) return a;
        int add = (n - a) > 0 ? (n - a) : 0;
        n = (n - a) > 0 ? a : n;
        return 1ll * n * (2 * a + (n - 1) * d) / 2 + add;
    }
    int maxValue(int n, int index, int maxSum) {
        long ans = 0;
        long l = 1 , r = maxSum;
        while(l <= r)
        {
            long m = (l + r) / 2;
            long totalSum = 0;
            totalSum += apSum(m - 1 , -1 , index);
            totalSum += apSum(m , -1 , n - index);
            if(totalSum > maxSum) r = m - 1;
            else
            {
                ans = m;
                l = m + 1;
            }
        }

        return ans;
    }
};