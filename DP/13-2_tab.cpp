#include<bits/stdc++.h>
using namespace std;

int solve(int a[], int n) {
	vector<int> dp(n + 1);
	dp[0] = 0; dp[1] = a[0];

	for (int i = 2; i <= n; i++) {
		dp[i] = max(dp[i - 1], dp[i - 2] + a[i - 1]);
	}
	return dp[n];
}

int main() {
	int n = 4, a[] = {10, 5, 15, 20};

	cout << solve(a, n);

	return 0;
}