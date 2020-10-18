#include<bits/stdc++.h>
using namespace std;

bool isPlalandrome(string s, int i, int j) {
	while (i < j) {
		if (s[i] == s[j])
			i++, j--;
		else
			return 0;
	}
	return 1;
}

int solve(string s, int n) {
	vector<vector<int>> dp(n + 1, vector<int>(n + 1));

	for (int i = 0; i <= n; i++)
		dp[i][i] = 0;

	for (int gap = 1; gap < n; gap++) {
		for (int i = 0; i + gap < n; i++) {
			int j = i + gap;
			if (isPlalandrome(s, i, j))
				dp[i][j] = 0;
			else {
				dp[i][j] = INT_MAX;
				for (int k = i; k < j; k++)
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + 1);
			}
		}
	}
	return dp[0][n - 1];
}

int main() {
	string s = "geek";
	cout << solve(s, s.length());

	return 0;
}