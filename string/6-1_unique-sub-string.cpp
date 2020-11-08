#include<bits/stdc++.h>
using namespace std;

int solve(string s) {
	int n = s.length();

	vector<long long> p_pow(n), h(n + 1);
	p_pow[0] = 1; h[0] = 0;

	int d = 31;
	int m = 1e9 + 9;

	for (int i = 1; i < n; i++) {
		p_pow[i] = ( p_pow[i - 1] * d ) % m;
	}

	for (int i = 1; i <= n; i++) {
		h[i] = (h[i - 1] + s[i - 1] * p_pow[i - 1]) % m;
	}

	int count = 0;
	long long cur_h;

	for (int j = 1; j <= n; j ++) {
		set<long long> st;
		for (int i = 0; i <= n - j; i++) {
			cur_h = (h[i + j] + m - h[i]) % m;
			cur_h *= p_pow[n - i - 1];
			st.insert(cur_h);
		}
		count += st.size();
	}

	return count;
}

int main() {

	string s = "ababa";
	cout << solve(s);

	return 0;
}