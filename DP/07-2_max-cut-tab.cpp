#include<bits/stdc++.h>
using namespace std;

int solve(int a[], int n, int l)
{
    int **dp = new int*[n + 1];

    for(int i = 0; i <= n; i++)
        dp[i] = new int[l + 1];

    for(int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for(int i = 0; i <= l; i++)
        dp[0][i] = -1;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= l; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if(j >= a[i - 1])
                dp[i][j] = max(dp[i][j], dp[i][j - a[i - 1]] + 1);
        }
    }
    return dp[n][l];
}

int main()
{
    int n = 3;
    int a[] = {1, 2, 3};

    int l = 5;

    cout << solve(a, n, l);

    return 0;
}