#include<bits/stdc++.h>
using namespace std;

bool solve(string txt, string pat) {
	int n = txt.length();
	int m = pat.length();

	int d = 31;
	int mod = 1e9 + 9;

	vector<long long> p_pow(n);
	p_pow[0] = 1;

	for (int i = 1; i < n; i++) {
		p_pow[i] = (p_pow[i - 1] * d) % mod;
	}

	vector<long long> h(n + 1);
	h[0] = 0;
	for (int i = 0; i < n; i++) {
		h[i + 1] = (h[i] + txt[i] * p_pow[i]) % mod;
	}

	long long h_s = 0;
	for (int i = 0; i < m; i++) {
		h_s = (h_s + pat[i] * p_pow[i]) % mod;
	}

	for (int i = 0; i + m - 1 < n; i++) {
		long long cur = (h[i + m] + mod - h[i]) % mod;
		if (cur == h_s * p_pow[i] % mod) {
			return 1;
		}
	}

	return 0;
}

int main() {
	string txt = "GEEKS FOR GEEKS"; string pat = "GEEK";
	cout << solve(txt, pat);

	return 0;
}