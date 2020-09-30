#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int solve(int a[], int n, int val)
{
    if(val == 0)
        dp[n][val] = 0;
    else if(n == 0)
        dp[n][val] = INT_MAX;
    else if(dp[n][val] == -1)
    {
        int f, s;
        f = s = INT_MAX;

        f = solve(a, n - 1, val);
        if(val >= a[n - 1])
            s = solve(a, n, val - a[n - 1]);
        if(s != INT_MAX)
            s++;
        dp[n][val] = min(f, s);
    }
    return dp[n][val];
}

int main()
{
    int n = 3;
    int a[] = {25, 10, 5};

    int val = 30;

    memset(dp, -1, sizeof(dp));

    cout << solve(a, n, val);

    return 0;
}