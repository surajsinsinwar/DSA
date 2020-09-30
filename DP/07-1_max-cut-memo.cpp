#include<bits/stdc++.h>
using namespace std;

int solve(int a[], int n, int l)
{
    if(l == 0)
        dp[n][l] = 0;
    else if(n == 0)
        dp[n][l] = -1;
    else if(dp[n][l] == -1)
    {
        dp[n][l] = solve(a, n - 1, l);
        if(l >= a[n - 1])
            p[n][l] = max(temp, solve(a, n, l - a[n - 1]) + 1);
    }
    
    return dp[n][l];
}

int main()
{
    int n = 3;
    int a[] = {1, 2, 3};

    int l = 5;

    memset(dp, -1, sizeof(dp));

    cout << solve(a, n, l);

    return 0;
}