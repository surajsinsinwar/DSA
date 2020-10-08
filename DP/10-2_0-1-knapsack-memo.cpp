#include<bits/stdc++.h>
using namespace std;

int solve(int v[], int w[], int n, int wt, vector<vector<int>> &dp){
    if(n == 0)
        return 0;
    if(dp[n][wt] != -1)
        return dp[n][wt];
    dp[n][wt] = solve(v, w, n - 1, wt, dp);
    if(wt >= w[n - 1])
        dp[n][wt] = max(dp[n][wt], solve(v, w, n - 1, wt - w[n - 1], dp) + v[n - 1]);
    return dp[n][wt];
}

int main(){

    int n = 4, wt = 10;
    int v[] = {10, 40, 30, 50}, w[] = {5, 4, 6, 3};

    vector<vector<int>> dp(n + 1, vector<int>(wt + 1, -1));

    cout << solve(v, w, n, wt, dp) << "\n";
    return 0;
}