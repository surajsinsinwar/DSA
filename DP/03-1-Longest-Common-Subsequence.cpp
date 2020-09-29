#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int lcs(string s1, string s2, int n, int m)
{
    if(n < 0 || m < 0)
        return 0;
    if(dp[n][m] != -1)
        return dp[n][m];
    else
    {
        if(s1[n] == s2[m])
            dp[n][m] = 1 + lcs(s1, s2, n - 1, m - 1);
        else
            dp[n][m] = max(lcs(s1, s2, n - 1, m), lcs(s1, s2, n, m - 1));
    }
    return dp[n][m];
}

int main()
{
    string s1 = "AXYZ", s2 = "BAZ";

    int n = s1.length(), m = s2.length();

    memset(dp, -1, sizeof(dp));

    cout << lcs(s1, s2, n - 1, m - 1);

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}