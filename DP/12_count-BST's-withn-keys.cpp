#include<bits/stdc++.h>
using namespace std;

int solve(int n) {
	vector<int> dp(n + 1, 0);
	dp[0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			dp[i] += dp[j] * dp[i - j - 1];
		}
	}

	return dp[n];
}

int main() {
	int n = 5;
	cout << solve(n);

	return 0;
}