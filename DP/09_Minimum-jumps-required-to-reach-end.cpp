#include<bits/stdc++.h>
using namespace std;

int solve(int a[], int n)
{
    int *dp = new int[n];
    dp[0] = 0;

    for(int i = 1; i < n; i++)
    {
        dp[i] = INT_MAX;
        for(int j = 0; j < i; j++)
        {
            if(a[j] + j >= i && dp[j] != INT_MAX)
                dp[i] = min(dp[i], dp[j] + 1);
        }
    }
    return dp[n - 1];
}

int main()
{
    int n = 6;
    int a[] = {3, 4, 2, 1, 2, 1};

    printf("%d\n", solve(a, n));
}