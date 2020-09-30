#include<bits/stdc++.h>
using namespace std;

int solve(int a[], int n, int val)
{
    int **dp = new int*[n + 1];

    for(int i = 0; i <= n; i++)
        dp[i] = new int [val + 1];

    for(int i = 0; i <= val; i++)
        dp[0][i] = LLONG_MAX;
    for(int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= val; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if(a[i - 1] <= j && dp[i][j - a[i - 1]] != LLONG_MAX)
                dp[i][j] = min(dp[i][j], dp[i][j - a[i - 1]] + 1);
        }
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