#include<bits/stdc++.h>
using namespace std;

int solve(int v[], int w[], int n, int wt){
    vector<vector<int>> dp(n + 1, vector<int>(wt + 1));

    for(int i = 0; i <= wt; i++)
        dp[0][i] = 0;
    for(int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= wt; j++){
            dp[i][j] = dp[i - 1][j];
            if(j >= w[i - 1])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
        }
    }
    return dp[n][wt];
}

int main(){

    int n = 4, wt = 10;
    int v[] = {10, 40, 30, 50}, w[] = {5, 4, 6, 3};

    cout << solve(v, w, n, wt) << "\n";
    return 0;
}