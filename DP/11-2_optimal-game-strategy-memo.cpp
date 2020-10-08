#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];

int solve(int a[], int i, int j) {
	if (i + 1 == j)
		return max(a[i], a[j]);
	if (dp[i][j] != -1)
		return dp[i][j];
	int m = min(solve(a, i + 2, j), solve(a, i + 1, j - 1)) + a[i];
	int n = min(solve(a, i, j - 2), solve(a, i + 1, j - 1)) + a[j];
	return dp[i][j] = max(m, n);
}

int main() {
	int a[] = {20, 5, 4, 6};
	int n = sizeof(a) / sizeof(a[0]);

	memset(dp, -1, sizeof(dp));

	cout << solve(a, 0, n - 1);

	return 0;
}