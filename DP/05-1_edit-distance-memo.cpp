#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int solve(string s1, string s2, int n, int m)
{
    if(n == 0)
        dp[n][m] = m;
    else if(m == 0)
        dp[n][m] = n;
    else if(dp[n][m] == -1)
    {
        if(s1[n - 1] == s2[m - 1])
            dp[n][m] = solve(s1, s2, n - 1, m - 1);
        else
            dp[n][m] = 1 + min(solve(s1, s2, n - 1, m - 1), min(solve(s1, s2, n, m - 1), solve(s1, s2, n - 1, m)));
    }
    return dp[n][m];
}

int main()
{
    string s1 = "saturday", s2 = "sunday";
    int n = s1.length(), m = s2.length();

    memset(dp, -1, sizeof(dp));

    cout << solve(s1, s2, n, m);

    return 0;
}