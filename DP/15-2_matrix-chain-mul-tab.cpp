#include<bits/stdc++.h>
using namespace std;

int solve(int a[], int n) {
	vector<vector<int>> dp(n + 1, vector<int> (n + 1));

	for (int i = 0; i <= n; i++)
		dp[i][i + 1] = 0;

	for (int gap = 2; gap < n; gap++) {
		for (int i = 0; i + gap < n; i++) {
			int j = i + gap;
			dp[i][j] = INT_MAX;
			for (int k = i + 1; k < j; k++)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + a[i] * a[k] * a[j]);
		}
	}
	return dp[0][n - 1];
}

int main() {
	int a[] = {20, 10, 30, 40};
	int n = sizeof(a) / sizeof(a[0]);

	cout << solve(a, n);

	return 0;
}