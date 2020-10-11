#include<bits/stdc++.h>
using namespace std;

int solve(int a[], int n, int sum) {
	vector<vector<int>> dp(n + 1, vector<int>(sum + 1));

	for (int i = 0; i <= n; i++)
		dp[i][0] = 1;
	for (int i = 1; i <= sum; i++)
		dp[0][i] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j >= a[i - 1])
				dp[i][j] += dp[i - 1][j - a[i - 1]];
		}
	}
	return dp[n][sum];
}

int main() {
	int n = 4, a[] = {10, 5, 15, 20}, sum = 15;

	cout << solve(a, n, sum);

	return 0;
}