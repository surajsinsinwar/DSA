#include<bits/stdc++.h>
using namespace std;

int memo[1001][1001];

int solve(int a[], int n, int sum)
{
    if(sum == 0)
        memo[sum][n] = 1;
    if(n == 0)
        memo[sum][n] = 0;

    if(memo[sum][n] == -1)
    {
        memo[sum][n] = solve(a, n - 1, sum);

        if(a[n - 1] <= sum)
            memo[sum][n] += solve(a, n, sum - a[n - 1]);
    }
    return memo[sum][n];
}

int main()
{
    int n = 3;

    int a[n] = {1, 2, 3};

    int sum = 4;

    memset(memo, -1, sizeof(memo));

    cout << solve(a, n, sum);

    return 0;
}